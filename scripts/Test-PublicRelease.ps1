[CmdletBinding()]
param(
    [string]$RepositoryRoot,
    [switch]$SkipHistory
)

Set-StrictMode -Version Latest
$ErrorActionPreference = 'Stop'
$global:LASTEXITCODE = 0

if ([string]::IsNullOrWhiteSpace($RepositoryRoot)) {
    $RepositoryRoot = Split-Path -Parent $PSScriptRoot
}

$RepositoryRoot = (Resolve-Path -LiteralPath $RepositoryRoot).Path
$gitRoot = (& git -C $RepositoryRoot rev-parse --show-toplevel 2>$null | Select-Object -First 1)
if ($LASTEXITCODE -ne 0 -or [string]::IsNullOrWhiteSpace($gitRoot)) {
    throw "Not a Git repository: $RepositoryRoot"
}

$gitRoot = (Resolve-Path -LiteralPath $gitRoot).Path
if (-not [string]::Equals($gitRoot, $RepositoryRoot, [StringComparison]::OrdinalIgnoreCase)) {
    throw "RepositoryRoot must be the Git root: $gitRoot"
}

$rules = @(
    [pscustomobject]@{
        Name = 'Windows user profile path'
        Pattern = '(?i)\b[A-Z]:[\\/]+Users[\\/]+(?!Public(?:[\\/]|$)|Default(?:[\\/]|$)|All Users(?:[\\/]|$))[^\\/\s"'']+'
    },
    [pscustomobject]@{
        Name = 'Private IPv4 address'
        Pattern = '(?<![\d.])(?:10\.(?:\d{1,3}\.){2}\d{1,3}|192\.168\.(?:\d{1,3}\.)\d{1,3}|172\.(?:1[6-9]|2\d|3[01])\.(?:\d{1,3}\.)\d{1,3})(?![\d.])'
    },
    [pscustomobject]@{
        Name = 'Internal hostname or URL'
        Pattern = '(?i)\b(?:https?|ssh)://[^\s/"'']*(?:\.internal|\.corp|\.intranet)(?:[/:][^\s"'']*)?'
    },
    [pscustomobject]@{
        Name = 'GitHub token-shaped value'
        Pattern = '\bgh(?:p|o|u|s|r)_[A-Za-z0-9]{20,}\b'
    },
    [pscustomobject]@{
        Name = 'Secret-like assignment'
        Pattern = '(?i)\b(?:api[_-]?key|access[_-]?token|client[_-]?secret|password)\b\s*[:=]\s*["'']?[A-Za-z0-9+/_=-]{16,}'
    },
    [pscustomobject]@{
        Name = 'Private key header'
        Pattern = ('-----BEGIN ' + '(?:RSA |EC |OPENSSH )?PRIVATE KEY-----')
    }
)

$textExtensions = [System.Collections.Generic.HashSet[string]]::new(
    [StringComparer]::OrdinalIgnoreCase
)
@(
    '.c', '.cc', '.cmake', '.cpp', '.csv', '.h', '.hpp', '.in', '.ini',
    '.json', '.md', '.ps1', '.psm1', '.txt', '.xml', '.yaml', '.yml'
) | ForEach-Object { [void]$textExtensions.Add($_) }

$textNames = [System.Collections.Generic.HashSet[string]]::new(
    [StringComparer]::OrdinalIgnoreCase
)
@('.gitignore', '.gitattributes', 'CMakeLists.txt') |
    ForEach-Object { [void]$textNames.Add($_) }

$findings = [System.Collections.Generic.List[object]]::new()
$findingKeys = [System.Collections.Generic.HashSet[string]]::new(
    [StringComparer]::OrdinalIgnoreCase
)

function Add-Finding {
    param(
        [Parameter(Mandatory = $true)][string]$Scope,
        [Parameter(Mandatory = $true)][string]$Location,
        [Parameter(Mandatory = $true)][string]$Category
    )

    $key = "$Scope|$Location|$Category"
    if ($findingKeys.Add($key)) {
        $findings.Add([pscustomobject]@{
            Scope = $Scope
            Location = $Location
            Category = $Category
        })
    }
}

function Test-Content {
    param(
        [Parameter(Mandatory = $true)][string]$Content,
        [Parameter(Mandatory = $true)][string]$Scope,
        [Parameter(Mandatory = $true)][string]$Location
    )

    foreach ($rule in $rules) {
        if ([regex]::IsMatch($Content, $rule.Pattern)) {
            Add-Finding -Scope $Scope -Location $Location -Category $rule.Name
        }
    }
}

$repositoryFiles = @(& git -C $RepositoryRoot ls-files --cached --others --exclude-standard)
if ($LASTEXITCODE -ne 0) {
    throw 'Failed to enumerate repository files.'
}

$scannedFileCount = 0
foreach ($relativePath in $repositoryFiles) {
    $leafName = Split-Path -Leaf $relativePath
    $extension = [IO.Path]::GetExtension($relativePath)
    if (-not $textNames.Contains($leafName) -and -not $textExtensions.Contains($extension)) {
        continue
    }

    $fullPath = Join-Path $RepositoryRoot $relativePath
    if (-not (Test-Path -LiteralPath $fullPath -PathType Leaf)) {
        continue
    }

    try {
        $content = [IO.File]::ReadAllText($fullPath)
    }
    catch {
        Write-Warning "Skipped unreadable text candidate: $relativePath"
        continue
    }

    $scannedFileCount++
    Test-Content -Content $content -Scope 'workspace' -Location $relativePath
}

$historyCommitCount = 0
if (-not $SkipHistory) {
    $currentCommit = $null
    $seenCommits = [System.Collections.Generic.HashSet[string]]::new(
        [StringComparer]::OrdinalIgnoreCase
    )
    $historyLines = & git -C $RepositoryRoot log --all '--format=commit %H' -p --no-ext-diff --unified=0 -- .
    if ($LASTEXITCODE -ne 0) {
        throw 'Failed to scan Git history.'
    }

    foreach ($line in $historyLines) {
        if ($line -match '^commit ([0-9a-f]{40})$') {
            $currentCommit = $matches[1]
            if ($seenCommits.Add($currentCommit)) {
                $historyCommitCount++
            }
            continue
        }

        if ([string]::IsNullOrWhiteSpace($currentCommit) -or $line.Length -lt 2) {
            continue
        }
        if (($line[0] -ne '+' -and $line[0] -ne '-') -or
            $line.StartsWith('+++') -or $line.StartsWith('---')) {
            continue
        }

        Test-Content `
            -Content $line.Substring(1) `
            -Scope 'history' `
            -Location $currentCommit.Substring(0, 12)
    }
}

if ($findings.Count -gt 0) {
    Write-Host 'Public release check failed. Suspected sensitive content:' -ForegroundColor Red
    $findings |
        Sort-Object Scope, Location, Category |
        Format-Table Scope, Location, Category -AutoSize
    Write-Host 'Matched content is intentionally not printed. Inspect each location locally.' -ForegroundColor Yellow
    exit 1
}

$historySummary = if ($SkipHistory) {
    'history scan skipped'
}
else {
    "$historyCommitCount commits inspected"
}
Write-Host "Public release check passed: $scannedFileCount workspace files, $historySummary."
