cmake_minimum_required(VERSION 3.16)

project(camera)

find_package(OpenCV REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${OpenCV_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} PUBLIC ${OpenCV_LIBS})