cmake_minimum_required(VERSION 3.10)
project(RobotCommSystemServer)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(QT_VERSION 5)
set(REQUIRED_LIBS Core Network)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Network)

add_executable(${PROJECT_NAME} main.cpp main.h)

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
find_package(spdlog)

target_link_libraries(${PROJECT_NAME} PUBLIC ${REQUIRED_LIBS_QUALIFIED} spdlog::spdlog RobotCommSystem loggerFactory Qt_Util)

if (CMAKE_BUILD_TYPE MATCHES Debug)
    target_compile_definitions(${PROJECT_NAME} PUBLIC -D__DEBUG__)
endif ()

install(TARGETS ${PROJECT_NAME}
        CONFIGURATIONS ${CMAKE_BUILD_TYPE}
        EXPORT ${PROJECT_NAME}-targets
        PUBLIC_HEADER DESTINATION include/${PROJECT_NAME}
        ARCHIVE DESTINATION lib/${CMAKE_BUILD_TYPE}
        LIBRARY DESTINATION lib/${CMAKE_BUILD_TYPE}
        RUNTIME DESTINATION bin/${CMAKE_BUILD_TYPE})