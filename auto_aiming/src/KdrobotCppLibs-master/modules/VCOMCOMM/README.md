# VCOMCOMM 虚拟串口通信协议PC端

## PC端使用方法

添加子文件夹到工程中并将库连接到目标

示例CMake：

由于依赖Qt，需要自己添加Qt的内核，**没有Qt框架是不能使用Qt组件的**

```cmake
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(QT_VERSION 5)
set(REQUIRED_LIBS Core SerialPort)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::SerialPort)

set(CMAKE_CXX_STANDARD 14)

add_executable(${PROJECT_NAME} main.cpp)

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
find_package(spdlog)
find_package(loggerFactory)
find_package(VCOMCOMM)
target_link_libraries(${PROJECT_NAME} KdrobotCppLibs::VCOMCOMM spdlog::spdlog KdrobotCppLibs::loggerFactory ${REQUIRED_LIBS_QUALIFIED})
```

## 单片机端使用方法

使用STMCubeMX配置USB从机设备，并添加`USB_DEVICE`中间件，选择虚拟串口IP，默认配置即可，注意VID和PID和上位机一致

![image-20200924124251557](README.assets/image-20200924124251557.png)

创建工程后添加单片机端源文件并添加包含路径

找到`usbd_cdc_if.c`,在头部包含`VCOMCOMM.h`并向`CDC_Receive_FS`函数添加一行`VCOMM_Receive_FS(Buf, Len);`以调用接收函数

```c
static int8_t CDC_Receive_FS(uint8_t* Buf, uint32_t *Len)
{
/* USER CODE BEGIN 6 */
USBD_CDC_SetRxBuffer(&hUsbDeviceFS, &Buf[0]);
USBD_CDC_ReceivePacket(&hUsbDeviceFS);
//here
VCOMM_Receive_FS(Buf, Len);
return (USBD_OK);
/* USER CODE END 6 */
}
```

在其他地方包含`VCOMCOMM.h`并重写`VCOMM_CallBack`函数,例:

```c
void VCOMM_CallBack(uint8_t fun_code, uint16_t id, uint8_t* data, uint8_t len) {
printf("fun_code=%02X, id=%04x, len=%d\r\n", fun_code, id, len);
}
```