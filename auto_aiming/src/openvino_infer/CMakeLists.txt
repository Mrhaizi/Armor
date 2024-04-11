cmake_minimum_required(VERSION 3.17)
project(openvino)

find_package(OpenCV REQUIRED)
find_package(OpenVINO REQUIRED) # 必须放在find_package(InferenceEngine REQUIRED)find_package(ngraph REQUIRED)前面
find_package(InferenceEngine REQUIRED)
find_package(ngraph REQUIRED)
find_package(Eigen3 REQUIRED)

add_library(${PROJECT_NAME}   src/openvino.cpp include/openvino.h)

target_include_directories(${PROJECT_NAME} PUBLIC ${InferenceEngine_INCLUDE_DIRS})
target_include_directories(${PROJECT_NAME} PUBLIC ${ngraph_INCLUDE_DIRS})
target_include_directories(${PROJECT_NAME} PUBLIC include/)
target_include_directories(${PROJECT_NAME} PUBLIC ${Eigen3_INCLUDE_DIRS} )

target_link_libraries(${PROJECT_NAME}  ${OpenCV_LIBS} 
                                        ${OpenVINO_LIBRARIES}
                                        ${InferenceEngine_LIBRARIES}
                                        ${ngraph_LIBRARIES}
                                        Eigen3::Eigen)