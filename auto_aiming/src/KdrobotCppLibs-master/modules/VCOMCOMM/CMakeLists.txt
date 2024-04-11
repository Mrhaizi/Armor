cmake_minimum_required(VERSION 3.10)
project(VCOMCOMM)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON) # 用于处理包含了 Q_OBJECT 宏的类，以支持 Qt 的信号与槽机制。
set(CMAKE_AUTORCC ON) # 自动处理 .qrc 文件（Qt 资源文件），将资源文件转换为可在程序中使用的格式。
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(QT_VERSION 5)
set(REQUIRED_LIBS Core SerialPort)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::SerialPort)

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)

if (Qt${QT_VERSION}Core_FOUND AND Qt${QT_VERSION}SerialPort_FOUND)

    add_library(${PROJECT_NAME} source/VCOMCOMM.cpp include/VCOMCOMM.h) 
    target_link_libraries(${PROJECT_NAME} PUBLIC ${REQUIRED_LIBS_QUALIFIED})
    target_link_libraries(${PROJECT_NAME} PUBLIC loggerFactory Qt_Util)

    set(MY_PUBLIC_HEADERS
            "${CMAKE_CURRENT_SOURCE_DIR}/include/VCOMCOMM.h")

    set_target_properties(${PROJECT_NAME} PROPERTIES
            PUBLIC_HEADER "${MY_PUBLIC_HEADERS}"
            PUBLIC_LINK spdlog::spdlog)

    target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include/${PROJECT_NAME}>)

    install(TARGETS ${PROJECT_NAME}
            CONFIGURATIONS ${CMAKE_BUILD_TYPE}
            EXPORT ${PROJECT_NAME}-targets
            PUBLIC_HEADER DESTINATION include/${PROJECT_NAME}
            ARCHIVE DESTINATION lib/${CMAKE_BUILD_TYPE}
            LIBRARY DESTINATION lib/${CMAKE_BUILD_TYPE}
            RUNTIME DESTINATION bin/${CMAKE_BUILD_TYPE})

    install(EXPORT ${PROJECT_NAME}-targets
            NAMESPACE KdrobotCppLibs::
            FILE ${PROJECT_NAME}Config.cmake
            DESTINATION lib/cmake/${PROJECT_NAME})

else ()
    set(MSG "missing ")
    if (NOT Qt${QT_VERSION}SerialPort_FOUND)
        set(MSG "${MSG} Qt${QT_VERSION}SerialPort")
    endif ()
    if (NOT Qt${QT_VERSION}Core_FOUND)
        set(MSG "${MSG} Qt${QT_VERSION}Core")
    endif ()
    message(STATUS "cannot compile ${PROJECT_NAME} ${MSG}")
endif ()