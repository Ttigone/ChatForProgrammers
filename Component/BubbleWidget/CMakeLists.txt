cmake_minimum_required(VERSION 3.5)
project(Component)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)


set(INCLUDE_DIRS
    FileWidget.h
    TextWidget.h
    PictureWidget.h
    TimeWidget.h
    Bubble/BubbleInfo.h
    Bubble/BubbleItem.h
)

set(SRC_DIRS
    FileWidget.cpp
    TextWidget.cpp
    PictureWidget.cpp
    TimeWidget.cpp
    Bubble/BubbleInfo.cpp
    Bubble/BubbleItem.cpp
)

set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

add_library(${PROJECT_NAME} SHARED)

target_sources(${PROJECT_NAME} PRIVATE ${SRC_DIRS} ${INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Gui)
# target_link_libraries(${PROJECT_NAME} PUBLIC ${CMAKE_BINARY_DIR}/bin/ComApi)

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED TRUE
)

