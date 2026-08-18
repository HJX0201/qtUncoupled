[CmdletBinding()]
param(
    [ValidateRange(1, 5000)]
    [int]$ActionCount = 200,

    [ValidateRange(1, 100)]
    [int]$Repeat = 5,

    [ValidateSet('Debug', 'Release', 'RelWithDebInfo', 'MinSizeRel')]
    [string]$Configuration = 'Debug',

    [ValidateRange(1, 256)]
    [int]$Jobs = [Environment]::ProcessorCount,

    [switch]$Quick,

    [string]$QtPath = 'C:\Qt\Qt5.12.10\5.12.10\msvc2017_64',

    [string]$VsPath = 'C:\Program Files\Microsoft Visual Studio\2022\Professional'
)

Set-StrictMode -Version Latest
$ErrorActionPreference = 'Stop'

if ($Quick) {
    if (-not $PSBoundParameters.ContainsKey('ActionCount')) {
        $ActionCount = 30
    }
    if (-not $PSBoundParameters.ContainsKey('Repeat')) {
        $Repeat = 2
    }
}

$projectRoot = Split-Path -Parent $MyInvocation.MyCommand.Path
$variants = @('direct_binding', 'string_registry')
$scenarioOrder = @(
    'clean',
    'noop',
    'single_implementation',
    'single_function_header',
    'ui_header',
    'business_header'
)
$invariantCulture = [System.Globalization.CultureInfo]::InvariantCulture

function Import-VsEnvironment {
    param([Parameter(Mandatory = $true)][string]$InstallationPath)

    $vcvars = Join-Path $InstallationPath 'VC\Auxiliary\Build\vcvars64.bat'
    if (-not (Test-Path -LiteralPath $vcvars -PathType Leaf)) {
        throw "Cannot find vcvars64.bat: $vcvars"
    }

    $command = "call `"$vcvars`" >nul && set"
    $environmentLines = & $env:ComSpec /d /s /c $command
    if ($LASTEXITCODE -ne 0) {
        throw "Failed to initialize the Visual Studio x64 environment."
    }

    $seenNames = [System.Collections.Generic.HashSet[string]]::new(
        [System.StringComparer]::OrdinalIgnoreCase
    )
    foreach ($line in $environmentLines) {
        if ($line -match '^([^=]+)=(.*)$') {
            $name = $matches[1]
            if ($seenNames.Add($name)) {
                [Environment]::SetEnvironmentVariable($name, $matches[2], 'Process')
            }
        }
    }
}

function Invoke-LoggedCommand {
    param(
        [Parameter(Mandatory = $true)][string]$Executable,
        [Parameter(Mandatory = $true)][string[]]$Arguments,
        [Parameter(Mandatory = $true)][string]$LogPath
    )

    $logDirectory = Split-Path -Parent $LogPath
    New-Item -ItemType Directory -Force -Path $logDirectory | Out-Null

    $stopwatch = [System.Diagnostics.Stopwatch]::StartNew()
    $previousPreference = $ErrorActionPreference
    $ErrorActionPreference = 'Continue'
    try {
        & $Executable @Arguments 2>&1 | Out-File -LiteralPath $LogPath -Encoding utf8
        $exitCode = $LASTEXITCODE
    }
    finally {
        $ErrorActionPreference = $previousPreference
        $stopwatch.Stop()
    }

    [pscustomobject]@{
        ExitCode = $exitCode
        ElapsedMs = [Math]::Round($stopwatch.Elapsed.TotalMilliseconds, 3)
    }
}

function Invoke-RequiredCommand {
    param(
        [Parameter(Mandatory = $true)][string]$Executable,
        [Parameter(Mandatory = $true)][string[]]$Arguments,
        [Parameter(Mandatory = $true)][string]$LogPath,
        [Parameter(Mandatory = $true)][string]$Description
    )

    $result = Invoke-LoggedCommand -Executable $Executable -Arguments $Arguments -LogPath $LogPath
    if ($result.ExitCode -ne 0) {
        throw "$Description failed with exit code $($result.ExitCode). See $LogPath"
    }
    return $result
}

function Touch-GeneratedFile {
    param([Parameter(Mandatory = $true)][string]$Path)

    if (-not (Test-Path -LiteralPath $Path -PathType Leaf)) {
        throw "Generated benchmark file does not exist: $Path"
    }

    $item = Get-Item -LiteralPath $Path
    $newTimestamp = [DateTime]::UtcNow
    if ($newTimestamp -le $item.LastWriteTimeUtc) {
        $newTimestamp = $item.LastWriteTimeUtc.AddMilliseconds(1)
    }
    $item.LastWriteTimeUtc = $newTimestamp
}

function Get-MocFileCount {
    param([Parameter(Mandatory = $true)][string]$BuildDirectory)

    return @(
        Get-ChildItem -LiteralPath $BuildDirectory -Recurse -File -Filter 'moc_*.cpp' `
            -ErrorAction SilentlyContinue
    ).Count
}

function Get-Median {
    param([Parameter(Mandatory = $true)][double[]]$Values)

    $sorted = @($Values | Sort-Object)
    $middle = [int][Math]::Floor($sorted.Count / 2)
    if (($sorted.Count % 2) -eq 1) {
        return [double]$sorted[$middle]
    }
    return ([double]$sorted[$middle - 1] + [double]$sorted[$middle]) / 2.0
}

function Get-StandardDeviation {
    param(
        [Parameter(Mandatory = $true)][double[]]$Values,
        [Parameter(Mandatory = $true)][double]$Mean
    )

    if ($Values.Count -le 1) {
        return 0.0
    }
    $sum = 0.0
    foreach ($value in $Values) {
        $difference = $value - $Mean
        $sum += $difference * $difference
    }
    return [Math]::Sqrt($sum / $Values.Count)
}

if (-not (Test-Path -LiteralPath (Join-Path $QtPath 'lib\cmake\Qt5\Qt5Config.cmake'))) {
    throw "Qt5Config.cmake was not found under QtPath: $QtPath"
}

Import-VsEnvironment -InstallationPath $VsPath

$cmakeCommand = (Get-Command cmake.exe -ErrorAction Stop).Source
$ctestCommand = (Get-Command ctest.exe -ErrorAction Stop).Source
$ninjaInfo = Get-Command ninja.exe -ErrorAction SilentlyContinue
if ($null -eq $ninjaInfo) {
    $fallbackNinja = 'C:\Qt\Tools\Ninja\ninja.exe'
    if (-not (Test-Path -LiteralPath $fallbackNinja -PathType Leaf)) {
        throw 'ninja.exe was not found on PATH or under C:\Qt\Tools\Ninja.'
    }
    $ninjaCommand = $fallbackNinja
}
else {
    $ninjaCommand = $ninjaInfo.Source
}

$clInfo = Get-Command cl.exe -ErrorAction Stop
$qmakeCommand = Join-Path $QtPath 'bin\qmake.exe'
$qtBinPath = Join-Path $QtPath 'bin'
$qtPluginPath = Join-Path $QtPath 'plugins'
$env:Path = "$qtBinPath;$env:Path"
$env:QT_PLUGIN_PATH = $qtPluginPath
$qtVersion = (& $qmakeCommand -query QT_VERSION | Select-Object -First 1).Trim()
$qtSpec = (& $qmakeCommand -query QMAKE_XSPEC | Select-Object -First 1).Trim()
$cmakeVersion = (& $cmakeCommand --version | Select-Object -First 1).Trim()
$ninjaVersion = (& $ninjaCommand --version | Select-Object -First 1).Trim()
$compilerVersionLines = @(& $clInfo.Source 2>&1)
$compilerVersion = ($compilerVersionLines | Where-Object { $_ -match 'Compiler Version' } | Select-Object -First 1)
if ([string]::IsNullOrWhiteSpace($compilerVersion)) {
    $compilerVersion = ($compilerVersionLines | Select-Object -First 1)
}
$compilerVersion = "$compilerVersion".Trim()

$timestamp = Get-Date -Format 'yyyyMMdd-HHmmss'
$runRoot = Join-Path $projectRoot "benchmark-results\$timestamp"
$rawLogRoot = Join-Path $runRoot 'logs'
$buildRoot = Join-Path $projectRoot "benchmark-builds\$($Configuration.ToLowerInvariant())-$ActionCount"
New-Item -ItemType Directory -Force -Path $runRoot, $rawLogRoot, $buildRoot | Out-Null

$environmentInfo = [ordered]@{
    timestamp = (Get-Date).ToString('o')
    operatingSystem = [Environment]::OSVersion.VersionString
    processorCount = [Environment]::ProcessorCount
    jobs = $Jobs
    configuration = $Configuration
    actionCount = $ActionCount
    repetitions = $Repeat
    warmFileCache = $true
    qtVersion = $qtVersion
    qtBuildDirectoryName = Split-Path -Leaf $QtPath
    qtSpec = $qtSpec
    compiler = $compilerVersion
    cmake = $cmakeVersion
    ninjaVersion = $ninjaVersion
}
$environmentInfo | ConvertTo-Json -Depth 4 | Set-Content -LiteralPath (Join-Path $runRoot 'environment.json') -Encoding utf8

$buildDirectories = @{}
$mocCounts = @{}

Write-Host "Configuring Qt $qtVersion benchmark projects..."
foreach ($variant in $variants) {
    $buildDirectory = Join-Path $buildRoot $variant
    $buildDirectories[$variant] = $buildDirectory
    $configureLog = Join-Path $rawLogRoot "configure_$variant.log"
    $configureArguments = @(
        '-S', $projectRoot,
        '-B', $buildDirectory,
        '-G', 'Ninja',
        "-DCMAKE_BUILD_TYPE=$Configuration",
        "-DCMAKE_PREFIX_PATH=$QtPath",
        "-DCMAKE_MAKE_PROGRAM=$ninjaCommand",
        "-DBENCH_VARIANT=$variant",
        "-DBENCH_ACTION_COUNT=$ActionCount"
    )
    Invoke-RequiredCommand -Executable $cmakeCommand -Arguments $configureArguments `
        -LogPath $configureLog -Description "Configure $variant" | Out-Null
}

Write-Host 'Warming every variant and validating equivalent behavior...'
foreach ($variant in $variants) {
    $buildDirectory = $buildDirectories[$variant]
    Invoke-RequiredCommand -Executable $cmakeCommand `
        -Arguments @('--build', $buildDirectory, '--target', 'clean') `
        -LogPath (Join-Path $rawLogRoot "warm_clean_$variant.log") `
        -Description "Warm clean $variant" | Out-Null
    Invoke-RequiredCommand -Executable $cmakeCommand `
        -Arguments @('--build', $buildDirectory, '--parallel', "$Jobs") `
        -LogPath (Join-Path $rawLogRoot "warm_build_$variant.log") `
        -Description "Warm build $variant" | Out-Null
    Invoke-RequiredCommand -Executable $ctestCommand `
        -Arguments @('--test-dir', $buildDirectory, '--output-on-failure') `
        -LogPath (Join-Path $rawLogRoot "ctest_$variant.log") `
        -Description "Behavior test $variant" | Out-Null
    $mocCounts[$variant] = Get-MocFileCount -BuildDirectory $buildDirectory
}

if ($mocCounts['direct_binding'] -ne $ActionCount) {
    throw "Expected $ActionCount direct-binding MOC files, found $($mocCounts['direct_binding'])."
}
if ($mocCounts['string_registry'] -ne 0) {
    throw "Expected no string-registry function MOC files, found $($mocCounts['string_registry'])."
}

$directMain = Join-Path $buildDirectories['direct_binding'] 'generated\direct_binding\main.cpp'
$registryGenerated = Join-Path $buildDirectories['string_registry'] 'generated\string_registry'
$registryMain = Join-Path $registryGenerated 'main.cpp'
$routerFiles = @(
    $registryMain,
    (Join-Path $registryGenerated 'action_router.h'),
    (Join-Path $registryGenerated 'action_router.cpp')
)
$directConnectCount = @(
    Select-String -LiteralPath $directMain -Pattern 'QObject::connect\(' -AllMatches
    | ForEach-Object { $_.Matches }
).Count
$registryConnectCount = @(
    Select-String -LiteralPath $registryMain -Pattern 'QObject::connect\(' -AllMatches
    | ForEach-Object { $_.Matches }
).Count
$concreteUiReferences = @(
    Select-String -LiteralPath $routerFiles -Pattern '\bFunction[0-9]+\b' -CaseSensitive
)
if ($directConnectCount -ne $ActionCount) {
    throw "Expected $ActionCount direct UI bindings, found $directConnectCount."
}
if ($registryConnectCount -ne 1) {
    throw "Expected one generic registry UI connection, found $registryConnectCount."
}
if ($concreteUiReferences.Count -ne 0) {
    throw 'String-registry UI/router code references a concrete FunctionN type.'
}

$rows = [System.Collections.Generic.List[object]]::new()

for ($round = 1; $round -le $Repeat; $round++) {
    Write-Host "Benchmark round $round of $Repeat..."
    $offset = ($round - 1) % $variants.Count
    $rotatedVariants = for ($position = 0; $position -lt $variants.Count; $position++) {
        $variants[($position + $offset) % $variants.Count]
    }

    foreach ($variant in $rotatedVariants) {
        $buildDirectory = $buildDirectories[$variant]
        $generatedDirectory = Join-Path $buildDirectory "generated\$variant"
        $roundLabel = $round.ToString('00', $invariantCulture)

        Invoke-RequiredCommand -Executable $cmakeCommand `
            -Arguments @('--build', $buildDirectory, '--target', 'clean') `
            -LogPath (Join-Path $rawLogRoot "round_${roundLabel}_${variant}_prepare_clean.log") `
            -Description "Prepare clean build for $variant" | Out-Null

        foreach ($scenario in $scenarioOrder) {
            switch ($scenario) {
                'single_implementation' {
                    $singleFile = if ($variant -eq 'direct_binding') {
                        Join-Path $generatedDirectory 'direct_function_0.cpp'
                    }
                    else {
                        Join-Path $generatedDirectory 'function_0.cpp'
                    }
                    Touch-GeneratedFile -Path $singleFile
                }
                'single_function_header' {
                    $singleHeader = if ($variant -eq 'direct_binding') {
                        Join-Path $generatedDirectory 'direct_function_0.h'
                    }
                    else {
                        Join-Path $generatedDirectory 'function_0.h'
                    }
                    Touch-GeneratedFile -Path $singleHeader
                }
                'ui_header' {
                    Touch-GeneratedFile -Path (Join-Path $generatedDirectory 'ui_context.h')
                }
                'business_header' {
                    Touch-GeneratedFile -Path (Join-Path $generatedDirectory 'business_context.h')
                }
            }

            $logPath = Join-Path $rawLogRoot "round_${roundLabel}_${variant}_${scenario}.log"
            $result = Invoke-RequiredCommand -Executable $cmakeCommand `
                -Arguments @('--build', $buildDirectory, '--parallel', "$Jobs") `
                -LogPath $logPath -Description "$variant $scenario build"

            $compiledObjectLines = @(
                Select-String -LiteralPath $logPath -Pattern 'Building CXX object' `
                    -ErrorAction SilentlyContinue
            )
            $functionObjectLines = @(
                $compiledObjectLines | Where-Object {
                    $_.Line -match '(direct_function_|function_)\d+\.cpp\.obj'
                }
            )

            $rows.Add([pscustomobject]@{
                Toolchain = 'MSVC2022-x64'
                QtVersion = $qtVersion
                Variant = $variant
                Scenario = $scenario
                Round = $round
                ActionCount = $ActionCount
                Configuration = $Configuration
                Jobs = $Jobs
                ElapsedMs = $result.ElapsedMs
                MocFileCount = $mocCounts[$variant]
                RecompiledObjectCount = $compiledObjectLines.Count
                RecompiledFunctionObjectCount = $functionObjectLines.Count
            })
        }
    }
}

$resultsCsv = Join-Path $runRoot 'results.csv'
$rows | Export-Csv -LiteralPath $resultsCsv -NoTypeInformation -Encoding utf8

$statistics = [System.Collections.Generic.List[object]]::new()
foreach ($scenario in $scenarioOrder) {
    foreach ($variant in $variants) {
        $values = [double[]]@(
            $rows | Where-Object { $_.Scenario -eq $scenario -and $_.Variant -eq $variant } |
                ForEach-Object { [double]$_.ElapsedMs }
        )
        $mean = [double](($values | Measure-Object -Average).Average)
        $statistics.Add([pscustomobject]@{
            Scenario = $scenario
            Variant = $variant
            MedianMs = Get-Median -Values $values
            MeanMs = $mean
            StdDevMs = Get-StandardDeviation -Values $values -Mean $mean
            MocFileCount = $mocCounts[$variant]
            MedianObjectCount = Get-Median -Values ([double[]]@(
                $rows | Where-Object { $_.Scenario -eq $scenario -and $_.Variant -eq $variant } |
                    ForEach-Object { [double]$_.RecompiledObjectCount }
            ))
            MedianFunctionObjectCount = Get-Median -Values ([double[]]@(
                $rows | Where-Object { $_.Scenario -eq $scenario -and $_.Variant -eq $variant } |
                    ForEach-Object { [double]$_.RecompiledFunctionObjectCount }
            ))
        })
    }
}

function Get-ScenarioStatistic {
    param(
        [Parameter(Mandatory = $true)][string]$Scenario,
        [Parameter(Mandatory = $true)][string]$Variant
    )

    return $statistics | Where-Object {
        $_.Scenario -eq $Scenario -and $_.Variant -eq $Variant
    } | Select-Object -First 1
}

function Get-ImprovementPercent {
    param(
        [Parameter(Mandatory = $true)][double]$BaselineMs,
        [Parameter(Mandatory = $true)][double]$CandidateMs
    )

    if ($BaselineMs -le 0.0) {
        return 0.0
    }
    return (($BaselineMs - $CandidateMs) / $BaselineMs) * 100.0
}

function Format-Duration {
    param([Parameter(Mandatory = $true)][double]$Milliseconds)

    if ($Milliseconds -ge 1000.0) {
        $millisecondsText = $Milliseconds.ToString('F0', $invariantCulture)
        $secondsText = ($Milliseconds / 1000.0).ToString('F2', $invariantCulture)
        return "$millisecondsText ms ($secondsText s)"
    }
    return "$($Milliseconds.ToString('F0', $invariantCulture)) ms"
}

function Get-RelativeBar {
    param(
        [Parameter(Mandatory = $true)][double]$ValueMs,
        [Parameter(Mandatory = $true)][double]$BaselineMs,
        [int]$Width = 20
    )

    $filled = if ($BaselineMs -gt 0.0) {
        [int][Math]::Round(($ValueMs / $BaselineMs) * $Width)
    }
    else {
        0
    }
    $filled = [Math]::Max(1, [Math]::Min($Width, $filled))
    return ('█' * $filled) + ('░' * ($Width - $filled))
}

function Get-ChangePhrase {
    param(
        [Parameter(Mandatory = $true)][double]$BaselineMs,
        [Parameter(Mandatory = $true)][double]$CandidateMs
    )

    $improvement = Get-ImprovementPercent -BaselineMs $BaselineMs -CandidateMs $CandidateMs
    if ($improvement -ge 0.0) {
        return "减少 $($improvement.ToString('F1', $invariantCulture))%"
    }
    return "增加 $((-$improvement).ToString('F1', $invariantCulture))%"
}

$directClean = Get-ScenarioStatistic -Scenario 'clean' -Variant 'direct_binding'
$registryClean = Get-ScenarioStatistic -Scenario 'clean' -Variant 'string_registry'
$directSingle = Get-ScenarioStatistic -Scenario 'single_implementation' -Variant 'direct_binding'
$registrySingle = Get-ScenarioStatistic -Scenario 'single_implementation' -Variant 'string_registry'
$directFunctionHeader = Get-ScenarioStatistic -Scenario 'single_function_header' -Variant 'direct_binding'
$registryFunctionHeader = Get-ScenarioStatistic -Scenario 'single_function_header' -Variant 'string_registry'
$directUi = Get-ScenarioStatistic -Scenario 'ui_header' -Variant 'direct_binding'
$registryUi = Get-ScenarioStatistic -Scenario 'ui_header' -Variant 'string_registry'
$directBusiness = Get-ScenarioStatistic -Scenario 'business_header' -Variant 'direct_binding'
$registryBusiness = Get-ScenarioStatistic -Scenario 'business_header' -Variant 'string_registry'

$cleanImprovement = Get-ImprovementPercent -BaselineMs $directClean.MedianMs -CandidateMs $registryClean.MedianMs
$singleImprovement = Get-ImprovementPercent -BaselineMs $directSingle.MedianMs -CandidateMs $registrySingle.MedianMs
$uiImprovement = Get-ImprovementPercent -BaselineMs $directUi.MedianMs -CandidateMs $registryUi.MedianMs
$directCode = '`direct_binding`'
$registryCode = '`string_registry`'
$qActionTriggerCode = '`QAction::trigger()`'
$groupTriggeredCode = '`QActionGroup::triggered`'
$actionDataCode = '`QAction::data()`'
$featureIdCode = '`feature.NNN`'
$qtKitCode = '`' + (Split-Path -Leaf $QtPath) + '`'
$mocPairCode = '`' + "$($mocCounts['direct_binding']) / $($mocCounts['string_registry'])" + '`'

$summaryLines = [System.Collections.Generic.List[string]]::new()
$summaryLines.Add('# Qt 5.12.10 UI逐项绑定与字符注册表编译基准')
$summaryLines.Add('')
$summaryLines.Add('> **架构验证通过：新方案的 UI 只保存字符功能标识，经一个统一动作路由器查找并执行普通 C++ 功能类；UI 与路由代码均不引用具体功能类型。**')
$summaryLines.Add('')
$summaryLines.Add("*生成时间：$(Get-Date -Format 'yyyy-MM-dd HH:mm:ss') · Qt $qtVersion · MSVC x64 · $Configuration · $ActionCount 个功能 · $Repeat 次采样*")
$summaryLines.Add('')
$summaryLines.Add('## 技术摘要')
$summaryLines.Add('')
$summaryLines.Add("- **两组都实际从 $qActionTriggerCode 进入业务逻辑。** 旧组逐项连接 $ActionCount 个功能槽；新组只连接一次 $groupTriggeredCode，从 $actionDataCode 读取 $featureIdCode 后查找注册表。")
$summaryLines.Add("- **干净编译由 $(Format-Duration $directClean.MedianMs) 变为 $(Format-Duration $registryClean.MedianMs)，$(Get-ChangePhrase $directClean.MedianMs $registryClean.MedianMs)。**")
$summaryLines.Add("- **单功能实现变化由 $(Format-Duration $directSingle.MedianMs) 变为 $(Format-Duration $registrySingle.MedianMs)，$(Get-ChangePhrase $directSingle.MedianMs $registrySingle.MedianMs)。**")
$summaryLines.Add("- **MOC 数量由 $($mocCounts['direct_binding']) 降为 $($mocCounts['string_registry'])。** 新功能类不依赖 `QObject`、槽函数或 UI，可由菜单、工具栏、脚本和测试共同复用。")
$summaryLines.Add('- **编译差异是完整重构的综合结果。** 它同时包含字符路由、UI依赖隔离、独立工厂和普通C++功能类的影响，不能全部归因于字符串查找。')
$summaryLines.Add('')
$summaryLines.Add('| 干净编译变化 | 单实现增量变化 | UI头变化 | 新方案MOC |')
$summaryLines.Add('|---:|---:|---:|---:|')
$summaryLines.Add("| **$($cleanImprovement.ToString('+0.0;-0.0;0.0', $invariantCulture))%** | **$($singleImprovement.ToString('+0.0;-0.0;0.0', $invariantCulture))%** | **$($uiImprovement.ToString('+0.0;-0.0;0.0', $invariantCulture))%** | **$($mocCounts['string_registry'])** |")
$summaryLines.Add('')
$summaryLines.Add('## 两种绑定架构的编译耗时对照')
$summaryLines.Add('')
$summaryLines.Add("每个场景以 $directCode 为100%基准；条形越短表示构建越快，精确值为 $Repeat 次采样中位数。")
$summaryLines.Add('')
$summaryLines.Add('| 场景 | 方案 | 相对耗时 | 中位数 | 相对旧组 | 重编译对象 | 功能对象 |')
$summaryLines.Add('|---|---|---|---:|---:|---:|---:|')

$visualScenarios = @(
    [pscustomobject]@{ Name = '干净编译'; Key = 'clean' },
    [pscustomobject]@{ Name = '单实现增量'; Key = 'single_implementation' },
    [pscustomobject]@{ Name = '单功能头变化'; Key = 'single_function_header' },
    [pscustomobject]@{ Name = 'UI头变化'; Key = 'ui_header' },
    [pscustomobject]@{ Name = '业务头变化'; Key = 'business_header' }
)
foreach ($visualScenario in $visualScenarios) {
    $directStat = Get-ScenarioStatistic -Scenario $visualScenario.Key -Variant 'direct_binding'
    foreach ($variant in $variants) {
        $stat = Get-ScenarioStatistic -Scenario $visualScenario.Key -Variant $variant
        $improvement = Get-ImprovementPercent -BaselineMs $directStat.MedianMs -CandidateMs $stat.MedianMs
        $changeText = if ($variant -eq 'direct_binding') {
            '基准'
        }
        elseif ($improvement -ge 0.0) {
            "↓ $($improvement.ToString('F1', $invariantCulture))%"
        }
        else {
            "↑ $((-$improvement).ToString('F1', $invariantCulture))%"
        }
        $variantLabel = '`' + $variant + '`'
        $barLabel = '`' + (Get-RelativeBar -ValueMs $stat.MedianMs -BaselineMs $directStat.MedianMs) + '`'
        $summaryLines.Add("| $($visualScenario.Name) | $variantLabel | $barLabel | $(Format-Duration $stat.MedianMs) | $changeText | $($stat.MedianObjectCount.ToString('F0', $invariantCulture)) | $($stat.MedianFunctionObjectCount.ToString('F0', $invariantCulture)) |")
    }
}

$summaryLines.Add('')
$summaryLines.Add('## 新方案的运行调用链确实经过字符查找')
$summaryLines.Add('')
$summaryLines.Add('```text')
$summaryLines.Add('QAction::trigger()')
$summaryLines.Add('  → QActionGroup::triggered(QAction*)')
$summaryLines.Add('  → ActionRouter读取QAction::data()')
$summaryLines.Add('  → FunctionRegistry按feature.NNN查找')
$summaryLines.Add('  → IFunction::execute(FunctionInvocation)')
$summaryLines.Add('  → BusinessContext::run()')
$summaryLines.Add('```')
$summaryLines.Add('')
$summaryLines.Add("CTest还验证了全部 $ActionCount 次成功调用、固定校验和、未知字符查找失败以及重复标识注册失败。新UI入口和ActionRouter中不存在FunctionN具体类型引用。")
$summaryLines.Add('')
$summaryLines.Add('## 测试范围与指标定义')
$summaryLines.Add('')
$summaryLines.Add('| 项目 | 本次设置 |')
$summaryLines.Add('|---|---|')
$summaryLines.Add("| Qt | $qtVersion，预编译套件 $qtKitCode |")
$summaryLines.Add("| 编译器 | $compilerVersion |")
$summaryLines.Add("| 构建配置 | $Configuration，Ninja，$Jobs 个并行任务 |")
$summaryLines.Add("| 测试规模 | 两组各 $ActionCount 个功能，业务算法、参数和预期校验和相同 |")
$summaryLines.Add("| 采样规则 | 预热后 $Repeat 次有效采样，两组轮换执行顺序 |")
$summaryLines.Add('| 主指标 | `cmake --build`墙钟时间中位数；同时记录重编译对象数 |')
$summaryLines.Add('| 缓存条件 | 暖文件缓存；不清理Windows系统缓存 |')
$summaryLines.Add('| 不计入 | CMake配置、源码生成和运行性能 |')
$summaryLines.Add('')
$summaryLines.Add('场景定义：')
$summaryLines.Add('')
$summaryLines.Add('- **干净编译：** 清理目标产物后完整编译。')
$summaryLines.Add('- **空构建：** 源码无变化时再次执行构建。')
$summaryLines.Add('- **单实现增量：** 仅触碰一个功能实现文件。')
$summaryLines.Add('- **单功能头变化：** 触碰一个具体功能类头文件，观察依赖传播。')
$summaryLines.Add('- **UI头变化：** 触碰共享UI上下文头文件。')
$summaryLines.Add('- **业务头变化：** 触碰全部功能共同依赖的业务头文件。')
$summaryLines.Add('')
$summaryLines.Add('## 完整统计结果')
$summaryLines.Add('')
$summaryLines.Add("所有变化均相对 $directCode；正值表示新方案耗时更低。")
$summaryLines.Add('')
$summaryLines.Add('| 场景 | 方案 | 中位数ms | 平均ms | 标准差ms | 加速比 | 变化 | MOC | 对象数 | 功能对象 |')
$summaryLines.Add('|---|---|---:|---:|---:|---:|---:|---:|---:|---:|')

foreach ($scenario in $scenarioOrder) {
    $directMedian = [double](
        $statistics | Where-Object { $_.Scenario -eq $scenario -and $_.Variant -eq 'direct_binding' }
    ).MedianMs
    foreach ($variant in $variants) {
        $stat = $statistics | Where-Object { $_.Scenario -eq $scenario -and $_.Variant -eq $variant }
        $speedup = if ($stat.MedianMs -gt 0.0) { $directMedian / $stat.MedianMs } else { 0.0 }
        $change = Get-ImprovementPercent -BaselineMs $directMedian -CandidateMs $stat.MedianMs
        $summaryLines.Add(
            "| $scenario | $variant | $($stat.MedianMs.ToString('F3', $invariantCulture)) | $($stat.MeanMs.ToString('F3', $invariantCulture)) | $($stat.StdDevMs.ToString('F3', $invariantCulture)) | $($speedup.ToString('F2', $invariantCulture))x | $($change.ToString('+0.0;-0.0;0.0', $invariantCulture))% | $($stat.MocFileCount) | $($stat.MedianObjectCount.ToString('F0', $invariantCulture)) | $($stat.MedianFunctionObjectCount.ToString('F0', $invariantCulture)) |"
        )
    }
}

$summaryLines.Add('')
$summaryLines.Add('> **空构建提示：** 空构建通常只有几十毫秒，容易被进程启动和后台负载影响，不作为架构结论的主要依据。')
$summaryLines.Add('')
$summaryLines.Add('## 可信度与适用边界')
$summaryLines.Add('')
$summaryLines.Add('- 两组均通过CTest并产生相同固定校验和，实际动作触发链已验证。')
$summaryLines.Add("- MOC数量已验证为 $mocPairCode，符合旧组 $ActionCount 个功能槽、新组普通C++功能类的设计。")
$summaryLines.Add("- $Repeat 次交错采样降低了固定顺序和机器升温偏差，但不等价于硬件实验室测试。")
$summaryLines.Add('- 这是完整重构前后对照，而不是只替换查找键的单变量实验；结果不能全部归因于字符串映射。')
$summaryLines.Add('- 合成工程用于让依赖差异超过计时噪声，百分比不能直接外推到真实项目。')
$summaryLines.Add('- 未启用预编译头、Unity Build、ccache或sccache。')
$summaryLines.Add('')
$summaryLines.Add('## 建议的真实工程验证')
$summaryLines.Add('')
$summaryLines.Add('1. 选择10–20个现有逐项槽绑定功能，改用字符串注册表并保持业务算法不变。')
$summaryLines.Add('2. 分别修改UI头、单个功能头和公共业务头，记录实际重编译对象数。')
$summaryLines.Add('3. 对确有信号、属性或QML需求的功能保留QObject，其余功能使用普通C++接口。')
$summaryLines.Add('4. 保持真实工程现有PCH、Unity Build和并行配置不变，再进行A/B计时。')
$summaryLines.Add('')
$summaryLines.Add('---')
$summaryLines.Add('')
$summaryLines.Add('**可复现材料：** [原始计时数据](results.csv) · [脱敏测试环境](environment.json)')
$summaryLines.Add('')
$summaryLines.Add('> 原始构建与CTest日志可能包含本机安装路径，仅保留在本地，不作为公开报告的一部分。')

$summaryPath = Join-Path $runRoot 'summary.md'
$summaryLines | Set-Content -LiteralPath $summaryPath -Encoding utf8

Write-Host "Benchmark completed: $summaryPath"
Get-Content -LiteralPath $summaryPath
