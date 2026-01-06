# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\appScreenRecorderApp_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\appScreenRecorderApp_autogen.dir\\ParseCache.txt"
  "appScreenRecorderApp_autogen"
  )
endif()
