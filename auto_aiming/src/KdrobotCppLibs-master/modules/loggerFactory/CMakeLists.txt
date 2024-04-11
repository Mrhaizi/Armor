cmake_minimum_required(VERSION 3.10)
project(loggerFactory)

set(QT_VERSION 5)
set(REQUIRED_LIBS Core)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core)

#spdlog
find_package(spdlog)

#Qt
find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)

if (spdlog_FOUND AND Qt${QT_VERSION}Core_FOUND)

    if (CMAKE_SYSTEM_NAME MATCHES "Linux")
        message(STATUS "in Linux, BackTrace is Enable")

        add_library(${PROJECT_NAME}
                source/spdlogger.cpp
                source/BackTrace.cpp
                source/spdUtil.cpp
                include/spdlogger.h
                include/BackTrace.h
                include/QtCompatibilityLayer.h
                include/spdUtil.h)

        set(MY_PUBLIC_HEADERS
                "${CMAKE_CURRENT_SOURCE_DIR}/include/spdlogger.h"
                "${CMAKE_CURRENT_SOURCE_DIR}/include/QtCompatibilityLayer.h"
                "${CMAKE_CURRENT_SOURCE_DIR}/include/spdUtil.h"
                "${CMAKE_CURRENT_SOURCE_DIR}/include/BackTrace.h")
    else ()
        message(STATUS "not in Linux, BackTrace is Disable")

        add_library(${PROJECT_NAME}
                source/spdlogger.cpp
                source/spdUtil.cpp
                include/spdlogger.h
                include/QtCompatibilityLayer.h
                include/spdUtil.h)

        set(MY_PUBLIC_HEADERS
                "${CMAKE_CURRENT_SOURCE_DIR}/include/spdlogger.h"
                "${CMAKE_CURRENT_SOURCE_DIR}/include/QtCompatibilityLayer.h"
                "${CMAKE_CURRENT_SOURCE_DIR}/include/spdUtil.h")
    endif ()

    target_link_libraries(${PROJECT_NAME} PUBLIC spdlog::spdlog ${REQUIRED_LIBS_QUALIFIED})


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
    if (NOT spdlog_FOUND)
        set(MSG "${MSG} spdlog")
    endif ()
    if (NOT Qt${QT_VERSION}Core_FOUND)
        set(MSG "${MSG} Qt${QT_VERSION}Core")
    endif ()
    message(STATUS "cannot compile ${PROJECT_NAME} ${MSG}")
endif ()
