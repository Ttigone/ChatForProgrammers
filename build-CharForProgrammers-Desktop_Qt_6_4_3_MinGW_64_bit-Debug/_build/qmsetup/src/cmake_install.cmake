# Install script for directory: F:/MyProject/CharForProgrammers/external-modules/qwindowkit-main/qmsetup/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "F:/MyProject/CharForProgrammers/build-CharForProgrammers-Desktop_Qt_6_4_3_MinGW_64_bit-Debug/_install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
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

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("F:/MyProject/CharForProgrammers/build-CharForProgrammers-Desktop_Qt_6_4_3_MinGW_64_bit-Debug/_build/qmsetup/src/syscmdline/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("F:/MyProject/CharForProgrammers/build-CharForProgrammers-Desktop_Qt_6_4_3_MinGW_64_bit-Debug/_build/qmsetup/src/corecmd/cmake_install.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/qmsetup" TYPE FILE FILES
    "F:/MyProject/CharForProgrammers/build-CharForProgrammers-Desktop_Qt_6_4_3_MinGW_64_bit-Debug/_build/qmsetup/src/qmsetupConfig.cmake"
    "F:/MyProject/CharForProgrammers/build-CharForProgrammers-Desktop_Qt_6_4_3_MinGW_64_bit-Debug/_build/qmsetup/src/qmsetupConfigVersion.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/qmsetup/qmsetupTargets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/qmsetup/qmsetupTargets.cmake"
         "F:/MyProject/CharForProgrammers/build-CharForProgrammers-Desktop_Qt_6_4_3_MinGW_64_bit-Debug/_build/qmsetup/src/CMakeFiles/Export/c898391b709f3dc591a64b1f8521d40e/qmsetupTargets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/qmsetup/qmsetupTargets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/qmsetup/qmsetupTargets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/qmsetup" TYPE FILE FILES "F:/MyProject/CharForProgrammers/build-CharForProgrammers-Desktop_Qt_6_4_3_MinGW_64_bit-Debug/_build/qmsetup/src/CMakeFiles/Export/c898391b709f3dc591a64b1f8521d40e/qmsetupTargets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/qmsetup" TYPE FILE FILES "F:/MyProject/CharForProgrammers/build-CharForProgrammers-Desktop_Qt_6_4_3_MinGW_64_bit-Debug/_build/qmsetup/src/CMakeFiles/Export/c898391b709f3dc591a64b1f8521d40e/qmsetupTargets-release.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "F:/MyProject/CharForProgrammers/external-modules/qwindowkit-main/qmsetup/src/../include/")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/qmsetup/cmake" TYPE DIRECTORY FILES "F:/MyProject/CharForProgrammers/external-modules/qwindowkit-main/qmsetup/src/../cmake/")
endif()

