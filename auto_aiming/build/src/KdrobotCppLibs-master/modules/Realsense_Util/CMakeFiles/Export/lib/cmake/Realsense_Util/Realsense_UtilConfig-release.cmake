#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "KdrobotCppLibs::Realsense_Util" for configuration "Release"
set_property(TARGET KdrobotCppLibs::Realsense_Util APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(KdrobotCppLibs::Realsense_Util PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/Release/libRealsense_Util.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS KdrobotCppLibs::Realsense_Util )
list(APPEND _IMPORT_CHECK_FILES_FOR_KdrobotCppLibs::Realsense_Util "${_IMPORT_PREFIX}/lib/Release/libRealsense_Util.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
