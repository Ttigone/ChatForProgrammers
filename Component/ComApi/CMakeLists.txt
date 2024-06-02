cmake_minimum_required(VERSION 3.5)
project(ComApi)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(INCLUDE_DIRS
    unit.h
    Utils.h
)

set(SRC_DIRS
    ""
)

# 设置 动态库的路径是 主目录的 build
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

add_library(${PROJECT_NAME} SHARED)


target_sources(${PROJECT_NAME} PRIVATE ${SRC_DIRS} ${INCLUDE_DIRS})


set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED TRUE
)

target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIRS})
