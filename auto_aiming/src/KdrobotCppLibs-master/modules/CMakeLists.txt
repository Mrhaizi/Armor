cmake_minimum_required(VERSION 3.10)

if (NOT MODULES_PATH)
    set(MODULES_PATH "${CMAKE_CURRENT_SOURCE_DIR}")
endif ()

file(GLOB MODULES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/*/)

foreach (MODULE_DIR IN LISTS MODULES_DIR)
    if (NOT ${MODULE_DIR} MATCHES ".*CMakeLists.txt$")
        message(STATUS "Find module dir ${MODULE_DIR}")
        add_subdirectory(${MODULE_DIR})
    endif ()
endforeach ()
