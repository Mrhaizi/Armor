# Qt_Util模块

## 一、包含的内容

### 1.类

- `JsonConfig` 用于读取Json配置文件
- `MainThread` 封装的Qt启动框架

### 2.命名空间

- `CRC` CRC校验函数

## 二、依赖
 - `Qt5::Core`
 - `loggerFactory`
 - `spdlog`

## 三、CMake示例

```cmake
# Qt5Core spdlog loggerFactory Qt_Util 
find_package(Qt5Core)
find_package(spdlog)
find_package(loggerFactory)
find_package(Qt_Util)
target_link_libraries(${PROJECT_NAME} PUBLIC KdrobotCppLibs::Qt_Util KdrobotCppLibs::loggerFactory spdlog::spdlog Qt5::Core)
```
