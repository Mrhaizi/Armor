#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "KdrobotCppLibs::VCOMCOMM" for configuration "Debug"
set_property(TARGET KdrobotCppLibs::VCOMCOMM APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(KdrobotCppLibs::VCOMCOMM PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/Debug/libVCOMCOMM.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS KdrobotCppLibs::VCOMCOMM )
list(APPEND _IMPORT_CHECK_FILES_FOR_KdrobotCppLibs::VCOMCOMM "${_IMPORT_PREFIX}/lib/Debug/libVCOMCOMM.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
