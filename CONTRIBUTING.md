# 贡献指南

感谢你帮助改进 Qt UI 功能绑定编译基准。本指南面向第一次参与仓库开发的贡献者，说明如何选择 Issue、创建独立分支、验证修改并提交 Pull Request。

## 开发环境

仓库主要在 Windows PowerShell 环境下开发和验证。运行完整的快速验证需要：

- Windows PowerShell 5.1 或 PowerShell 7；
- Git；
- CMake 3.16 或更高版本；
- Ninja；
- Visual Studio 2022 的 x64 C++ 工具链；
- Qt 5.12.10 的 MSVC x64 套件，默认路径为 `C:\Qt\Qt5.12.10\5.12.10\msvc2017_64`。

若 Visual Studio 或 Qt 安装在其他位置，请通过 `-VsPath` 和 `-QtPath` 参数传入实际路径。运行前可检查基础工具：

```powershell
git --version
cmake --version
ninja --version
```

## 从 Issue 开始

如果你是第一次参与 GitHub 协作，可以先跟随[GitHub Bug 修复协作实战](docs/collaboration-tutorial.md)，通过真实教学 Issue 完成 Fork、修复、Pull Request、Code Review 和合并流程。

1. 在开始修改前阅读对应 Issue 的目标、范围和验收标准，并确认没有已存在的 Pull Request 重复处理该问题。
2. 将本地 `main` 更新到远程最新状态。
3. 从最新 `main` 创建一个只服务于该 Issue 的分支，不要直接在 `main` 上开发。

```powershell
git switch main
git pull --ff-only origin main
git switch -c docs/issue-3-contributing-guide
```

分支名应简短并体现修改类型和目标，例如：

- `docs/issue-3-contributing-guide`
- `ci/issue-2-windows-build`
- `fix/issue-5-published-source-check`

## 首次构建与快速验证

克隆仓库并进入工作目录：

```powershell
git clone https://github.com/HJX0201/qtUncoupled.git
Set-Location qtUncoupled
```

使用默认安装路径运行快速验证：

```powershell
.\Run-Benchmark.ps1 -Quick
```

如果工具安装在其他位置：

```powershell
.\Run-Benchmark.ps1 -Quick `
    -QtPath 'C:\Qt\Qt5.12.10\5.12.10\msvc2017_64' `
    -VsPath 'C:\Program Files\Microsoft Visual Studio\2022\Professional'
```

快速验证会为 `direct_binding` 和 `string_registry` 两种方案生成源码，执行结构检查、配置、编译和 CTest 行为验证。它不会修改仓库中已跟踪的发布源码。

也可以直接编译已发布的 200 功能源码；完整命令见 [README](README.md#运行)。

## 源码生成与发布快照

请区分以下三类文件：

- `cmake/GenerateBenchmarkSources.cmake` 是两种基准方案的正式源码生成器。修改测试架构时，应首先修改生成器。
- `published-sources/direct_binding/` 和 `published-sources/string_registry/` 是固定 200 功能的公开源码快照，供阅读、审查和独立编译。
- `benchmark-builds/` 中的源码和构建产物是本地生成内容，不是修改目标。

如果生成器的修改会改变固定 200 功能的输出，应使用仓库提供的导出命令同步发布快照：

```powershell
cmake `
    -DOUTPUT_DIR="$PWD/published-sources" `
    -P cmake/ExportPublishedSources.cmake
```

导出后检查差异并重新运行快速验证。不要直接编辑构建目录中的生成文件，也不要只修改发布快照而遗漏生成器中的对应修改。

## 提交修改

提交前先确认变更范围：

```powershell
git status --short
git diff --check
git diff
```

提交信息应简洁描述意图。一个 Pull Request 可以包含多个逻辑清晰的提交，但不要混入与 Issue 无关的重构或格式化修改。

```powershell
git add README.md CONTRIBUTING.md .github/pull_request_template.md
git commit -m "docs: add contributor workflow"
```

## 公开发布前的脱敏检查

本仓库是公开仓库。提交前必须检查暂存内容，避免泄露：

- 用户名、机器名和本机绝对路径；
- 内网地址、客户名、企业内部仓库地址；
- 密钥、令牌、密码和其他凭据；
- `.env` 等本地环境文件；
- 构建目录、结果目录和可能记录本机环境的原始日志。

禁止提交 `benchmark-builds/`、`benchmark-results/`、`build*/`、原始日志或其他本地产物。`.gitignore` 只能阻止未跟踪文件被意外加入，不能清除已经进入提交或 Git 历史的敏感信息。

提交前至少运行：

```powershell
git status --short
git diff --cached
```

如果发现敏感信息，立即停止推送，先从提交和历史中清除并轮换可能泄露的凭据。

## 推送和创建 Pull Request

将功能分支推送到远程：

```powershell
git push -u origin docs/issue-3-contributing-guide
```

随后在 GitHub 创建 Pull Request，目标分支选择 `main`。按照模板说明：

- 做了什么；
- 为什么这样修改；
- 如何验证以及验证结果；
- 已知风险或影响范围；
- 使用 `Closes #编号` 关联对应 Issue。

评审期间继续在同一分支提交并推送，Pull Request 会自动更新。处理意见前先拉取远程分支，修改后重新运行相关验证，并在对话中说明处理结果。

## 提交前检查清单

- [ ] 修改范围符合 Issue，且没有混入无关改动。
- [ ] 已检查工作区、暂存内容和新增文件。
- [ ] 已运行 `.\Run-Benchmark.ps1 -Quick`，或在 Pull Request 中说明无法运行的原因。
- [ ] 生成器和 `published-sources` 在需要时已同步。
- [ ] 未提交构建目录、结果目录、原始日志或敏感信息。
- [ ] Pull Request 已填写变更、原因、验证、风险和关联 Issue。
