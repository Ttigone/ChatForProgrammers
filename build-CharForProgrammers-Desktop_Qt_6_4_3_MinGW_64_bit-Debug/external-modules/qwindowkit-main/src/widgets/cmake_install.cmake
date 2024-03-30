# Install script for directory: F:/MyProject/CharForProgrammers/external-modules/qwindowkit-main/src/widgets

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/ChatForProgrammeras")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "D:/qt/qt6/Tools/mingw1120_64/bin/objdump.exe")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "F:/MyProject/CharForProgrammers/build-CharForProgrammers-Desktop_Qt_6_4_3_MinGW_64_bit-Debug/out-amd64-Debug/lib/libQWKWidgets.dll.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY OPTIONAL FILES "F:/MyProject/CharForProgrammers/build-CharForProgrammers-Desktop_Qt_6_4_3_MinGW_64_bit-Debug/out-amd64-Debug/bin/QWKWidgets.dll")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/QWKWidgets.dll" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/QWKWidgets.dll")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "D:/qt/qt6/Tools/mingw1120_64/bin/strip.exe" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/QWKWidgets.dll")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  
                get_filename_component(_install_dir "include/QWindowKit/QWKWidgets" ABSOLUTE BASE_DIR ${CMAKE_INSTALL_PREFIX})
        
                execute_process(
                    COMMAND "F:/MyProject/CharForProgrammers/build-CharForProgrammers-Desktop_Qt_6_4_3_MinGW_64_bit-Debug/_install/bin/qmcorecmd.exe" incsync -d 
                        "-s"  "F:/MyProject/CharForProgrammers/external-modules/qwindowkit-main/src/widgets" ${_install_dir}
                    WORKING_DIRECTORY "F:/MyProject/CharForProgrammers/external-modules/qwindowkit-main/src/widgets"
                    OUTPUT_VARIABLE _output_contents
                    OUTPUT_STRIP_TRAILING_WHITESPACE
                    COMMAND_ERROR_IS_FATAL ANY
                )
                string(REPLACE "\n" ";" _lines "${_output_contents}")

                foreach(_line ${_lines})
                    string(REGEX MATCH "from \"([^\"]*)\" to \"([^\"]*)\"" _ ${_line})
                    get_filename_component(_target_path ${CMAKE_MATCH_2} DIRECTORY)
                    file(INSTALL ${CMAKE_MATCH_1} DESTINATION ${_target_path})
                endforeach()
            
endif()

