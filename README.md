# Qt 5.12.10 UI功能绑定编译基准

[![Windows CI](https://github.com/HJX0201/qtUncoupled/actions/workflows/windows-ci.yml/badge.svg)](https://github.com/HJX0201/qtUncoupled/actions/workflows/windows-ci.yml)

本项目比较两种真实的UI功能调用架构，只测量编译和链接时间，不测试运行性能或主观耦合度。

当前机器完成的200功能、5次采样结果见[公开基准报告](docs/benchmark-report.md)，逐次计时见[results.csv](docs/results.csv)。公开材料已移除机器名、用户名和本机绝对路径。

仓库同时提交了可直接阅读和编译的[完整200功能C++源码](published-sources/README.md)：旧方案位于[`direct_binding`](published-sources/direct_binding)，新方案位于[`string_registry`](published-sources/string_registry)。运行基准时仍默认在构建目录生成源码，保证增量测试不会修改Git跟踪文件。

## 编译速度提升

> 在Qt 5.12.10、MSVC 2022 x64、Debug、200个功能、5次交错采样条件下，`string_registry`的干净编译中位数从 **17.75秒降至6.97秒**，耗时减少 **60.7%**，相当于 **2.55倍编译速度**。

| 编译场景 | UI逐项绑定 | 字符注册表 | 耗时减少 | 加速比 |
|---|---:|---:|---:|---:|
| 干净编译 | 17.75秒 | 6.97秒 | **60.7%** | **2.55x** |
| 单功能实现变化 | 689毫秒 | 330毫秒 | **52.2%** | **2.09x** |
| 单功能头变化 | 1.46秒 | 347毫秒 | **76.2%** | **4.21x** |
| UI头变化 | 1.40秒 | 1.22秒 | **12.8%** | **1.15x** |
| 共享业务头变化 | 16.23秒 | 6.97秒 | **57.0%** | **2.33x** |

同时，功能类产生的MOC文件数量由 **200个降为0个**。这意味着收益不仅体现在完整构建中，修改单个功能及公共业务头文件时也能明显减少编译等待。

上述提升来自完整解耦重构的综合效果，包括UI依赖隔离、普通C++功能类、独立工厂及字符注册表，不能把全部差异单独归因于字符串查找。具体结果取决于真实工程规模、头文件依赖和构建环境。

## 两组方案

### `direct_binding`：UI逐项绑定功能槽

- UI创建200个普通`QAction`。
- 每个动作分别`connect`到对应的`QObject/Q_OBJECT`功能类槽函数。
- UI入口包含全部具体功能类头文件。

```text
QAction::trigger()
  → QAction::triggered(bool)
  → DirectFunctionN::execute(bool)槽函数
  → BusinessContext::run()
```

### `string_registry`：UI通过字符标识查找功能

- UI只把`feature.000`等字符串写入`QAction::data()`。
- 200个动作加入一个非互斥`QActionGroup`。
- UI只建立一次通用连接，不存在逐功能槽绑定。
- `ActionRouter`读取字符标识，交给`FunctionRegistry`查找普通C++功能类。
- UI和路由器不包含或引用任何具体`FunctionN`类型。

```text
QAction::trigger()
  → QActionGroup::triggered(QAction*)
  → ActionRouter读取QAction::data()
  → FunctionRegistry按feature.NNN查找
  → IFunction::execute(FunctionInvocation)
  → BusinessContext::run()
```

具体功能通过独立工厂创建。集中注册代码只依赖工厂声明，不包含具体功能类定义。

## 等价性验证

两组都实际触发全部动作，并验证相同业务参数、执行次数和固定校验和。字符串方案还验证：

- 未知功能标识返回失败且不执行功能；
- 重复功能标识注册失败且不覆盖原功能；
- UI和`ActionRouter`中没有具体功能类型引用；
- 旧组有200次逐项连接，新组只有1次通用连接；
- MOC数量分别为200和0。

## 环境

- Qt 5.12.10：`C:\Qt\Qt5.12.10\5.12.10\msvc2017_64`
- Visual Studio 2022 x64编译器
- CMake、Ninja、C++17
- 默认Debug、200个功能、5次交错采样

## 持续集成

Pull Request 创建或更新以及推送到 `main` 时，Windows CI 会分别配置、编译并测试 `direct_binding` 和 `string_registry`。CI 固定使用仓库内的 200 功能发布源码，不生成或改写 Git 跟踪文件，也不在共享 runner 上比较性能数据。

本地复现 CI：

```powershell
$qtPath = 'C:\Qt\Qt5.12.10\5.12.10\msvc2017_64'

foreach ($variant in @('direct_binding', 'string_registry')) {
    $buildDirectory = "build-ci-$variant"
    cmake -S . -B $buildDirectory -G Ninja `
        -DCMAKE_BUILD_TYPE=Debug `
        "-DCMAKE_PREFIX_PATH=$qtPath" `
        "-DBENCH_VARIANT=$variant" `
        -DBENCH_ACTION_COUNT=200 `
        -DBENCH_USE_PUBLISHED_SOURCES=ON
    cmake --build $buildDirectory --config Debug --parallel 2
    ctest --test-dir $buildDirectory --build-config Debug --output-on-failure
}
```

上述检查只验证配置、编译和行为等价性。正式性能基准仍应在受控的本地环境中通过 `Run-Benchmark.ps1` 执行。

## 运行

正式基准：

```powershell
.\Run-Benchmark.ps1
```

快速结构和行为验证：

```powershell
.\Run-Benchmark.ps1 -Quick
```

直接编译仓库中已发布的200功能源码：

```powershell
cmake -S . -B build-published-direct -G Ninja `
    -DCMAKE_PREFIX_PATH='C:\Qt\Qt5.12.10\5.12.10\msvc2017_64' `
    -DBENCH_VARIANT=direct_binding `
    -DBENCH_ACTION_COUNT=200 `
    -DBENCH_USE_PUBLISHED_SOURCES=ON
cmake --build build-published-direct
ctest --test-dir build-published-direct --output-on-failure
```

将`BENCH_VARIANT`改为`string_registry`即可编译新方案源码。

可调整参数：

```powershell
.\Run-Benchmark.ps1 `
    -ActionCount 200 `
    -Repeat 5 `
    -Configuration Debug `
    -Jobs 8 `
    -QtPath 'C:\Qt\Qt5.12.10\5.12.10\msvc2017_64' `
    -VsPath 'C:\Program Files\Microsoft Visual Studio\2022\Professional'
```

## 编译场景

| 场景 | 含义 |
|---|---|
| `clean` | 清理目标产物后的完整编译 |
| `noop` | 源码无变化的空构建 |
| `single_implementation` | 修改一个功能实现文件 |
| `single_function_header` | 修改一个具体功能类头文件 |
| `ui_header` | 修改共享UI上下文头文件 |
| `business_header` | 修改全部功能共同依赖的业务头文件 |

报告记录墙钟中位数、均值、标准差、MOC数量、重编译对象数和其中的功能对象数。

## 输出

- `benchmark-builds/debug-200/direct_binding/`
- `benchmark-builds/debug-200/string_registry/`
- `benchmark-results/<时间戳>/summary.md`
- `benchmark-results/<时间戳>/results.csv`
- `benchmark-results/<时间戳>/environment.json`
- `benchmark-results/<时间戳>/logs/`

构建目录中的测试代码由[生成器](cmake/GenerateBenchmarkSources.cmake)产生。需要修改测试架构时应修改生成器，不应直接修改构建目录。

`benchmark-builds/`和`benchmark-results/`仅用于本地运行并已被Git忽略。原始日志可能包含本机安装路径，不应直接提交；脚本生成的`environment.json`默认不记录机器名、用户名或工具绝对路径。

## 结果解释边界

该测试比较的是完整重构前后架构，差异同时包含字符路由、UI依赖隔离、独立工厂和普通C++功能类的影响，不能把全部编译差异归因于字符串查找。合成项目的百分比也不能直接外推到真实工程。
