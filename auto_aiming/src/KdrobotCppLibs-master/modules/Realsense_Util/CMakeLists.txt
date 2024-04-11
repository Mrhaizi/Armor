cmake_minimum_required(VERSION 3.10)
project(Realsense_Util)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(QT_VERSION 5)
set(REQUIRED_LIBS Core)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core realsense2::realsense2)

find_package(OpenCV)
find_package(realsense2)
find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)

if (Qt${QT_VERSION}Core_FOUND AND realsense2_FOUND AND OpenCV_FOUND)
    file(GLOB SRCS ${CMAKE_CURRENT_SOURCE_DIR}/source/* ${CMAKE_CURRENT_SOURCE_DIR}/include/*)
    add_library(${PROJECT_NAME} ${SRCS})

    target_link_libraries(${PROJECT_NAME} PRIVATE ${REQUIRED_LIBS_QUALIFIED} ${OpenCV_LIBS} loggerFactory Qt_Util)
    target_include_directories(${PROJECT_NAME} PRIVATE ${OpenCV_INCLUDE_DIRS})

    if (CMAKE_BUILD_TYPE MATCHES Debug)
        target_compile_definitions(${PROJECT_NAME} PRIVATE -D__DEBUG__)
    endif ()

    set(MY_PUBLIC_HEADERS
            "${CMAKE_CURRENT_SOURCE_DIR}/include/Realsense.h"
            "${CMAKE_CURRENT_SOURCE_DIR}/include/RealsenseFrame.h")

    set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER "${MY_PUBLIC_HEADERS}")

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
    if (NOT realsense2_FOUND)
        set(MSG "${MSG} realsense2")
    endif ()
    if (NOT Qt${QT_VERSION}Core_FOUND)
        set(MSG "${MSG} Qt${QT_VERSION}Core")
    endif ()
    if (NOT OpenCV_FOUND)
        set(MSG "${MSG} OpenCV")
    endif ()
    message(STATUS "cannot compile ${PROJECT_NAME} ${MSG}")
endif ()


