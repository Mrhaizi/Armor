cmake_minimum_required(VERSION 3.17)

project(camera)

set(PROJ_DIR "/home/mayuqi/桌面/Armor/auto_aiming/camera_data")#是目录，不是文件

find_package(fmt REQUIRED)
find_package(OpenCV REQUIRED)

link_directories("${PROJ_DIR}/lib/64")
link_libraries("${PROJ_DIR}/lib/64/libMvCameraControl.so")

add_library(${PROJECT_NAME}   src/adjustcamera.cpp include/adjustcamera.h)
target_include_directories(${PROJECT_NAME} PUBLIC ${OpenCV_INCLUDE_DIRS})
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJ_DIR}/include)
target_include_directories(${PROJECT_NAME} PUBLIC include/)

target_link_libraries(${PROJECT_NAME}  -lX11)
# target_link_libraries(${PROJECT_NAME} libMvCameraControl.so)