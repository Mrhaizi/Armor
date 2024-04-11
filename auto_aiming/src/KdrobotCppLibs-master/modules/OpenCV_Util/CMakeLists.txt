cmake_minimum_required(VERSION 3.10)
project(OpenCV_Util)

find_package(OpenCV)
find_package(spdlog)
find_package(OpenMP)

if (OpenCV_FOUND AND spdlog_FOUND)
    file(GLOB SRCS ${CMAKE_CURRENT_SOURCE_DIR}/source/* ${CMAKE_CURRENT_SOURCE_DIR}/include/*)
    add_library(${PROJECT_NAME} ${SRCS})

    target_include_directories(${PROJECT_NAME} PRIVATE ${OpenCV_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS} spdlog::spdlog)

    set(MY_PUBLIC_HEADERS
            "${CMAKE_CURRENT_SOURCE_DIR}/include/OpenCV_Util.h"
            "${CMAKE_CURRENT_SOURCE_DIR}/include/coordinate.h"
            "${CMAKE_CURRENT_SOURCE_DIR}/include/PNP_Calculate.h")

    set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER "${MY_PUBLIC_HEADERS}")

    target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include/${PROJECT_NAME}>)

    if (OpenMP_CXX_FOUND)
        target_compile_options(${PROJECT_NAME} PUBLIC
                ${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS})
    endif ()

    install(TARGETS ${PROJECT_NAME}
            CONFIGURATIONS ${CMAKE_BUILD_TYPE}
            EXPORT ${PROJECT_NAME}-targets
            PUBLIC_HEADER DESTINATION include/${PROJECT_NAME}
            ARCHIVE DESTINATION lib/${CMAKE_BUILD_TYPE}
            LIBRARY DESTINATION lib/${CMAKE_BUILD_TYPE}
            RUNTIME DESTINATION bin/${CMAKE_BUILD_TYPE})

    install(DIRECTORY matlab/ DESTINATION matlab)

    install(EXPORT ${PROJECT_NAME}-targets
            NAMESPACE KdrobotCppLibs::
            FILE ${PROJECT_NAME}Config.cmake
            DESTINATION lib/cmake/${PROJECT_NAME})
else ()
    set(MSG "missing ")
    if (NOT spdlog_FOUND)
        set(MSG "${MSG} Qt${QT_VERSION}")
    endif ()
    if (NOT OpenCV_FOUND)
        set(MSG "${MSG} OpenCV")
    endif ()
    message(STATUS "cannot compile ${PROJECT_NAME} ${MSG}")
endif ()


