# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\SerialDemo_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\SerialDemo_autogen.dir\\ParseCache.txt"
  "SerialDemo_autogen"
  )
endif()
