cmake_minimum_required(VERSION 3.17)
project(kit)

find_package(OpenCV REQUIRED)

add_library(${PROJECT_NAME} include/kit.h  src/kit.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${OpenCV_INCLUDE_DIRS})
target_include_directories(${PROJECT_NAME} PUBLIC include/)
target_link_libraries(${PROJECT_NAME}  ${OpenCV_LIBS})