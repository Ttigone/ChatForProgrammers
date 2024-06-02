cmake_minimum_required(VERSION 3.5)

project(ChatForProgrammers VERSION 0.1 LANGUAGES CXX)

# ----------------------------------------------------------------
# Build Options
option(BUILD_WIDGETFRAME "WidgetFrame" ON)
option(BUILD_QWINDOWKIT-MAIN "WindowKit" ON)
option(BUILD_DEBUG_MODEL "extra debug module message" OFF)
option(BUILD_QT-MATERIAL-WIDGETS "qt-material-widgets" ON)

# ----------------------------------------------------------------
# Setting variables
# ----------------------------------------------------------------
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCES
        src/main.cpp
        src/App.cpp
        src/App.h
        # only can change .exe's icon
        # ./resources/windowbar/app/ico.rc
)


# ----------------------------------------------------------------
# Find Package
# ----------------------------------------------------------------
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)



if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(${PROJECT_NAME}
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        res.qrc
        src/LoginPage/LoginDialog.h src/LoginPage/LoginDialog.cpp
        src/MainPage/MainMsgBox.h src/MainPage/MainMsgBox.cpp
        src/MainPage/MainChatList.h src/MainPage/MainChatList.cpp
        src/MainPage/MainChatModel.h src/MainPage/MainChatModel.cpp
        src/MainPage/SearchWidget.h src/MainPage/SearchWidget.cpp
        src/FriendPage/FriendList.h src/FriendPage/FriendList.cpp
        src/StorePage/StoreList.h src/StorePage/StoreList.cpp
        src/MainPage/MainMsgWidget.h src/MainPage/MainMsgWidget.cpp
        src/MainPage/CommunicationView.h src/MainPage/CommunicationView.cpp
        src/MainPage/CommunicationModel.h src/MainPage/CommunicationModel.cpp
        src/MainPage/SendMsgWidget.h src/MainPage/SendMsgWidget.cpp
        src/Sys/SysConfig.h src/Sys/SysConfig.cpp
        src/Sys/CellData.h src/Sys/CellData.cpp
        src/Sys/MiddleWare.h src/Sys/MiddleWare.cpp

    )

# Define target properties for Android with Qt 6 as:
#    set_property(TARGET QNet APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(${PROJECT_NAME} SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(${PROJECT_NAME}
            ${PROJECT_SOURCES}
        )
    endif()
endif()


# ----------------------------------------------------------------
# Include Dir
# ----------------------------------------------------------------
include_directories(${PROJECT_SOURCE_DIR}/3rdparty)
include_directories(${PROJECT_SOURCE_DIR}/Component)
include_directories(${PROJECT_SOURCE_DIR}/src)

# QsLog
include_directories(${PROJECT_SOURCE_DIR}/3rdparty/QsLog/include)

# ----------------------------------------------------------------
# Add source modules
# ----------------------------------------------------------------
add_subdirectory(Component/ComApi)
add_subdirectory(Component/BubbleWidget)
if (BUILD_WIDGETFRAME)
    add_subdirectory(Component/WidgetFrame)
endif()
if (BUILD_DEBUG_MODEL)
    add_subdirectory(3rdparty/qt-easy-logger-main)
endif()
if (BUILD_QWINDOWKIT-MAIN)
    add_subdirectory(3rdparty/qwindowkit-main)
endif()
if (BUILD_QT-MATERIAL-WIDGETS)
    add_subdirectory(3rdparty/qt-material)
endif()


# ----------------------------------------------------------------
# linking module
# ----------------------------------------------------------------
target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
if (BUILD_DEBUG_MODEL)
    target_link_libraries(${PROJECT_NAME} PRIVATE qt-easy-logger)
endif()
if (BUILD_WIDGETFRAME)
    target_link_libraries(${PROJECT_NAME} PRIVATE WidgetFrame)
endif()
if (BUILD_QWINDOWKIT-MAIN)
    target_link_libraries(${PROJECT_NAME} PRIVATE QWindowKit::Widgets)
endif()
if (BUILD_QT-MATERIAL-WIDGETS)
    target_link_libraries(${PROJECT_NAME} PRIVATE qt-material)
endif()


target_link_libraries(${PROJECT_NAME} PRIVATE ComApi)
target_link_libraries(${PROJECT_NAME} PRIVATE Component)


link_libraries(${PROJECT_SOURCE_DIR}/3rdparty/QsLog/bin)
# QsLog lib
# target_link_libraries(${PROJECT_NAME} PRIVATE
# message(${PROJECT_SOURCE_DIR}/3rdparty/QsLog/bin/QsLog2.dll)




# ----------------------------------------------------------------
# Set Icon of Window
# ----------------------------------------------------------------
function(add_win_rc _target)
    set(RC_VERSION "0.0.0.0")
    set(RC_VERSION_STRING "0.0.0.0")

    set(RC_DESCRIPTION ${_target})
    set(RC_COPYRIGHT ${_target})
    set(RC_APPLICATION_NAME ${_target})

    get_filename_component(RC_ICON_PATH "${CMAKE_CURRENT_SOURCE_DIR}/resources/Icon/windowbar/app/chat.ico" ABSOLUTE)


    set(_out_path "${CMAKE_CURRENT_BINARY_DIR}/${_target}_res.rc")
    configure_file("${CMAKE_CURRENT_SOURCE_DIR}/resources/cmake/WinResource.rc.in" ${_out_path} @ONLY)
    target_sources(${_target} PRIVATE ${_out_path})

endfunction()
# execute function
add_win_rc(${PROJECT_NAME})

# set app version'file
function(add_win_manifest _target)
    set(_name ${_target})
    set(_version "0.0.0.0")
    set(_desc ${_name})

    set(MANIFEST_IDENTIFIER ${_name})
    set(MANIFEST_VERSION ${_version})
    set(MANIFEST_DESCRIPTION ${_desc})
    set(MANIFEST_UTF8)
    set(_out_path "${CMAKE_CURRENT_BINARY_DIR}/${_target}_manifest.manifest")
    # message(_out_path)
    configure_file("${CMAKE_CURRENT_SOURCE_DIR}/resources/cmake/WinManifest.manifest.in" ${_out_path} @ONLY)
    target_sources(${_target} PRIVATE ${_out_path})
endfunction()
add_win_manifest(${PROJECT_NAME})




# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.${PROJECT_NAME})
endif()
set_target_properties(${PROJECT_NAME} PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME} 
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(${PROJECT_NAME})
endif()

