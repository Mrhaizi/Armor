cmake_minimum_required(VERSION 3.10)
project(detect_armor)


find_package(fmt REQUIRED)
find_package(OpenCV REQUIRED)


add_subdirectory(./src/KdrobotCppLibs-master)
add_subdirectory(./src/kit)
add_subdirectory(./src/openvino_infer)
add_subdirectory(./src/camera)

file(GLOB_RECURSE SRC  ${PROJECT_SOURCE_DIR}/src/detect_armor/src/*.cpp ./src/main1.cpp)

add_executable(${PROJECT_NAME} ${SRC})

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/src/detect_armor/include)
target_include_directories(${PROJECT_NAME} PUBLIC ./src/KdrobotCppLibs/modules/VCOMCOMM/include)


target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS}
                                              fmt::fmt)
target_link_libraries(${PROJECT_NAME} VCOMCOMM)
target_link_libraries(${PROJECT_NAME} camera)
target_link_libraries(${PROJECT_NAME} kit)
target_link_libraries(${PROJECT_NAME} openvino)