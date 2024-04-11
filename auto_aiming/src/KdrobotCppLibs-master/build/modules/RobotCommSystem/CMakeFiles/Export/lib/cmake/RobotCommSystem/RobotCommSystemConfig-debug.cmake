#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "KdrobotCppLibs::RobotCommSystem" for configuration "Debug"
set_property(TARGET KdrobotCppLibs::RobotCommSystem APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(KdrobotCppLibs::RobotCommSystem PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/Debug/libRobotCommSystem.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS KdrobotCppLibs::RobotCommSystem )
list(APPEND _IMPORT_CHECK_FILES_FOR_KdrobotCppLibs::RobotCommSystem "${_IMPORT_PREFIX}/lib/Debug/libRobotCommSystem.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
