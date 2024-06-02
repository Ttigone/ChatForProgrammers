project(qt-material)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

file(GLOB PROJECT_SOURCES
    components/*.cpp
    components/*.h
    components/lib/*.cpp
    components/lib/*.h
    components/layouts/*.cpp
    components/layouts/*.h
)
find_package(Qt6 REQUIRED COMPONENTS StateMachine)

add_library(${PROJECT_NAME} STATIC)

set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

target_sources(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::StateMachine)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Gui)

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED TRUE
)

target_include_directories(${PROJECT_NAME} PUBLIC components/*.h components/lib/.*h components/layouts/*.h)
