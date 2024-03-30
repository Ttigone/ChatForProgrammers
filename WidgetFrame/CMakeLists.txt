project(WidgetFrame)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# 搜索该目录下的所有文件
file(GLOB _src *.h *.cpp)

# 编译静态库
add_library(${PROJECT_NAME} STATIC)

# 编译文件 
target_sources(${PROJECT_NAME} PRIVATE ${_src}) 

# 库文件
target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Gui)

# 编译属性
set_target_properties(${PROJECT_NAME} PROPERTIES 
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED TRUE  # 不满足 cpp 17 报错
)

target_include_directories(${PROJECT_NAME} PUBLIC . ..)




