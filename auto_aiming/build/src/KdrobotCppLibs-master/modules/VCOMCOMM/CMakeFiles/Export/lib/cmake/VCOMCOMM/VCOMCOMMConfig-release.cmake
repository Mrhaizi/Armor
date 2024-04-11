#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "KdrobotCppLibs::VCOMCOMM" for configuration "Release"
set_property(TARGET KdrobotCppLibs::VCOMCOMM APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(KdrobotCppLibs::VCOMCOMM PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/Release/libVCOMCOMM.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS KdrobotCppLibs::VCOMCOMM )
list(APPEND _IMPORT_CHECK_FILES_FOR_KdrobotCppLibs::VCOMCOMM "${_IMPORT_PREFIX}/lib/Release/libVCOMCOMM.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
