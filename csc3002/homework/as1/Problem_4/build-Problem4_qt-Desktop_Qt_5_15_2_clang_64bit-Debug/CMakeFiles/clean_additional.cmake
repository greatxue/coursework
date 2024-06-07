# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Problem4_qt_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Problem4_qt_autogen.dir/ParseCache.txt"
  "Problem4_qt_autogen"
  )
endif()
