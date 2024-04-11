cmake_minimum_required(VERSION 3.10)

project(KdrobotCppLibs)

set(BUILD_TYPE Debug Release RelWithDebInfo MinSizeRel)
if (CMAKE_BUILD_TYPE)
    list(FIND BUILD_TYPE ${CMAKE_BUILD_TYPE} RESULT)
    if (RESULT MATCHES -1)
        message(FATAL_ERROR
                "Unknown Build Type: ${CMAKE_BUILD_TYPE}\n"
                "Support type is ${BUILD_TYPE}")
    endif ()
else ()
    set(CMAKE_BUILD_TYPE Release)
endif ()

if (WIN32)
    set(CMAKE_INSTALL_PREFIX "C:/KdrobotCppLibs")
    if (MSVC)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /utf-8")
    else ()
        message(FATAL_ERROR "Unknown Compiler")
    endif ()
elseif (UNIX)
    set(CMAKE_INSTALL_PREFIX "/usr/local/KdrobotCppLibs")
    if (GNU)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
    endif ()
endif ()

add_subdirectory(modules)

message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Configuration complete use 'make install' to install")
message(STATUS "Install prefix: '${CMAKE_INSTALL_PREFIX}'")
if (CMAKE_BUILD_TYPE MATCHES Release)
    if (WIN32)
        message(STATUS "Environment variables that should be added:
    PATH += ${CMAKE_INSTALL_PREFIX}/bin
    CMAKE_PREFIX_PATH += ${CMAKE_INSTALL_PREFIX}/lib/${CMAKE_BUILD_TYPE}/cmake")
    elseif (UNIX)
        message(STATUS "Environment variables that should be added:
    export PATH=${CMAKE_INSTALL_PREFIX}/bin/${CMAKE_BUILD_TYPE}\${PATH:+:\${PATH}}
    export CMAKE_PREFIX_PATH=${CMAKE_INSTALL_PREFIX}/lib/${CMAKE_BUILD_TYPE}/cmake\${CMAKE_PREFIX_PATH:+:\${CMAKE_PREFIX_PATH}}")
    endif ()
endif ()
