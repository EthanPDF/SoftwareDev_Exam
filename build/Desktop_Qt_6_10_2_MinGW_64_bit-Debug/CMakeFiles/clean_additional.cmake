# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\SoftwareDev_Exam_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\SoftwareDev_Exam_autogen.dir\\ParseCache.txt"
  "SoftwareDev_Exam_autogen"
  )
endif()
