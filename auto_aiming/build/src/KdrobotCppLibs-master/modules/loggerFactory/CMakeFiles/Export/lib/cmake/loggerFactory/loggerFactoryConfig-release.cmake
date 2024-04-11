#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "KdrobotCppLibs::loggerFactory" for configuration "Release"
set_property(TARGET KdrobotCppLibs::loggerFactory APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(KdrobotCppLibs::loggerFactory PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/Release/libloggerFactory.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS KdrobotCppLibs::loggerFactory )
list(APPEND _IMPORT_CHECK_FILES_FOR_KdrobotCppLibs::loggerFactory "${_IMPORT_PREFIX}/lib/Release/libloggerFactory.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
