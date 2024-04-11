#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "KdrobotCppLibs::loggerFactory" for configuration "Debug"
set_property(TARGET KdrobotCppLibs::loggerFactory APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(KdrobotCppLibs::loggerFactory PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/Debug/libloggerFactory.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS KdrobotCppLibs::loggerFactory )
list(APPEND _IMPORT_CHECK_FILES_FOR_KdrobotCppLibs::loggerFactory "${_IMPORT_PREFIX}/lib/Debug/libloggerFactory.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
