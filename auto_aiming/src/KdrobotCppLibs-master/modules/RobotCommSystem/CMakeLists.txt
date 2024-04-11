cmake_minimum_required(VERSION 3.10)
project(RobotCommSystem)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(QT_VERSION 5)
set(REQUIRED_LIBS Core Network)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Network)

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)

if (Qt${QT_VERSION}Core_FOUND AND Qt${QT_VERSION}Network_FOUND)
    file(GLOB SRCS ${CMAKE_CURRENT_SOURCE_DIR}/source/* ${CMAKE_CURRENT_SOURCE_DIR}/include/*)
    add_library(RobotCommSystem ${SRCS})

    target_link_libraries(RobotCommSystem PRIVATE ${REQUIRED_LIBS_QUALIFIED})

    target_link_libraries(RobotCommSystem PRIVATE loggerFactory Qt_Util)

    set(MY_PUBLIC_HEADERS
            "${CMAKE_CURRENT_SOURCE_DIR}/include/HostAddressRadio.h"
            "${CMAKE_CURRENT_SOURCE_DIR}/include/RCS_Client.h"
            "${CMAKE_CURRENT_SOURCE_DIR}/include/RCS_Server.h"
            "${CMAKE_CURRENT_SOURCE_DIR}/include/TcpConnect.h")

    set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER "${MY_PUBLIC_HEADERS}")

    target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include/${PROJECT_NAME}>)

    add_subdirectory(RobotCommSystemServer)

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
    if (NOT Qt${QT_VERSION}Network_FOUND)
        set(MSG "${MSG} Qt${QT_VERSION}Network")
    endif ()
    if (NOT Qt${QT_VERSION}Core_FOUND)
        set(MSG "${MSG} Qt${QT_VERSION}Core")
    endif ()
    message(STATUS "cannot compile ${PROJECT_NAME} ${MSG}")
endif ()

