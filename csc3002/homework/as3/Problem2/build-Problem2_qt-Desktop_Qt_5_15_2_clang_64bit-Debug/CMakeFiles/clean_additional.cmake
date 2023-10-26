# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Problem2_qt_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Problem2_qt_autogen.dir/ParseCache.txt"
  "Problem2_qt_autogen"
  )
endif()
