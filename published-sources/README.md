# 固定200功能的完整C++源码

这里保存基准项目实际使用的两套200功能源码，便于直接阅读、代码审查和独立编译。

- [`direct_binding`](direct_binding)：200个带`Q_OBJECT`的功能类，UI逐项连接到功能槽函数。
- [`string_registry`](string_registry)：200个普通C++功能类，UI通过`QAction::data()`中的字符标识交给统一路由器查找并执行。

这些文件由[`GenerateBenchmarkSources.cmake`](../cmake/GenerateBenchmarkSources.cmake)生成，但已经作为普通`.cpp/.h`文件提交到仓库。默认基准仍在构建目录生成同样的源码，以确保触碰文件的增量测试不会修改这里的公开快照。

使用`-DBENCH_USE_PUBLISHED_SOURCES=ON`可让顶层CMake直接编译本目录中的源码。该模式固定要求`BENCH_ACTION_COUNT=200`。

重新导出快照：

```powershell
cmake `
    -DOUTPUT_DIR="$PWD/published-sources" `
    -P cmake/ExportPublishedSources.cmake
```
