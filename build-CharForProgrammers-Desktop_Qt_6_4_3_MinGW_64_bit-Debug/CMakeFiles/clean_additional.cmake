# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\ChatForProgrammeras_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ChatForProgrammeras_autogen.dir\\ParseCache.txt"
  "ChatForProgrammeras_autogen"
  "external-modules\\qt-easy-logger-main\\CMakeFiles\\qt-easy-logger-sample_autogen.dir\\AutogenUsed.txt"
  "external-modules\\qt-easy-logger-main\\CMakeFiles\\qt-easy-logger-sample_autogen.dir\\ParseCache.txt"
  "external-modules\\qt-easy-logger-main\\CMakeFiles\\qt-easy-logger_autogen.dir\\AutogenUsed.txt"
  "external-modules\\qt-easy-logger-main\\CMakeFiles\\qt-easy-logger_autogen.dir\\ParseCache.txt"
  "external-modules\\qt-easy-logger-main\\qt-easy-logger-sample_autogen"
  "external-modules\\qt-easy-logger-main\\qt-easy-logger_autogen"
  "external-modules\\qwindowkit-main\\src\\core\\CMakeFiles\\QWKCore_autogen.dir\\AutogenUsed.txt"
  "external-modules\\qwindowkit-main\\src\\core\\CMakeFiles\\QWKCore_autogen.dir\\ParseCache.txt"
  "external-modules\\qwindowkit-main\\src\\core\\QWKCore_autogen"
  "external-modules\\qwindowkit-main\\src\\widgets\\CMakeFiles\\QWKWidgets_autogen.dir\\AutogenUsed.txt"
  "external-modules\\qwindowkit-main\\src\\widgets\\CMakeFiles\\QWKWidgets_autogen.dir\\ParseCache.txt"
  "external-modules\\qwindowkit-main\\src\\widgets\\QWKWidgets_autogen"
  "lib\\WidgetFrame\\CMakeFiles\\WidgetFrame_autogen.dir\\AutogenUsed.txt"
  "lib\\WidgetFrame\\CMakeFiles\\WidgetFrame_autogen.dir\\ParseCache.txt"
  "lib\\WidgetFrame\\WidgetFrame_autogen"
  "lib\\qt-material\\CMakeFiles\\qt-material_autogen.dir\\AutogenUsed.txt"
  "lib\\qt-material\\CMakeFiles\\qt-material_autogen.dir\\ParseCache.txt"
  "lib\\qt-material\\qt-material_autogen"
  )
endif()
