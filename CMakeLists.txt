cmake_minimum_required(VERSION 3.5)

project(ChatForProgrammeras VERSION 0.1 LANGUAGES CXX)

# ----------------------------------------------------------------
# Build Options
option(BUILD_WIDGETFRAME "build WidgetFrame" ON)
option(BUILD_QWINDOWKIT-MAIN "WindowKit" ON)
option(BUILD_DEBUG_MODEL "extra debug module message" ON)

# ----------------------------------------------------------------
# Setting variables
# ----------------------------------------------------------------
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCES
        main.cpp
        widget.cpp
        widget.h
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
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/external-modules)



# ----------------------------------------------------------------
# Add source modules
# ----------------------------------------------------------------
if (BUILD_DEBUG_MODEL)
    add_subdirectory(external-modules/qt-easy-logger-main)
endif()
if (BUILD_QWINDOWKIT-MAIN)
    add_subdirectory(./external-modules/qwindowkit-main)
endif()
if (BUILD_WIDGETFRAME)
    add_subdirectory(WidgetFrame)
endif()


# ----------------------------------------------------------------
# linking module
# ----------------------------------------------------------------
target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
if (BUILD_DEBUG_MODEL)
    target_link_libraries(${PROJECT_NAME} PRIVATE qt-easy-logger)
endif()
if (BUILD_QWINDOWKIT-MAIN)
    target_link_libraries(${PROJECT_NAME} PRIVATE QWindowKit::Widgets)
endif()
if (BUILD_WIDGETFRAME)
    target_link_libraries(${PROJECT_NAME} PRIVATE WidgetFrame)
endif()


# ----------------------------------------------------------------
# Set Icon of Window
# ----------------------------------------------------------------
function(add_win_rc _target)
    set(RC_VERSION "0.0.0.0")
    set(RC_VERSION_STRING "0.0.0.0")

    set(RC_DESCRIPTION ${_target})
    set(RC_COPYRIGHT ${_target})
    set(RC_APPLICATION_NAME ${_target})

    get_filename_component(RC_ICON_PATH "${CMAKE_CURRENT_SOURCE_DIR}/resources/windowbar/app/network.ico" ABSOLUTE)


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
