#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "KdrobotCppLibs::OpenCV_Util" for configuration "Debug"
set_property(TARGET KdrobotCppLibs::OpenCV_Util APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(KdrobotCppLibs::OpenCV_Util PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/Debug/libOpenCV_Util.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS KdrobotCppLibs::OpenCV_Util )
list(APPEND _IMPORT_CHECK_FILES_FOR_KdrobotCppLibs::OpenCV_Util "${_IMPORT_PREFIX}/lib/Debug/libOpenCV_Util.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
