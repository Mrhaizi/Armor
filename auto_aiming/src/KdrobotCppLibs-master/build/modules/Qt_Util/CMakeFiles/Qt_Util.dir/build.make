# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mzy/Desktop/KdrobotCppLibs-master

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mzy/Desktop/KdrobotCppLibs-master/build

# Include any dependencies generated for this target.
include modules/Qt_Util/CMakeFiles/Qt_Util.dir/depend.make

# Include the progress variables for this target.
include modules/Qt_Util/CMakeFiles/Qt_Util.dir/progress.make

# Include the compile flags for this target's objects.
include modules/Qt_Util/CMakeFiles/Qt_Util.dir/flags.make

modules/Qt_Util/CMakeFiles/Qt_Util.dir/Qt_Util_autogen/mocs_compilation.cpp.o: modules/Qt_Util/CMakeFiles/Qt_Util.dir/flags.make
modules/Qt_Util/CMakeFiles/Qt_Util.dir/Qt_Util_autogen/mocs_compilation.cpp.o: modules/Qt_Util/Qt_Util_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mzy/Desktop/KdrobotCppLibs-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object modules/Qt_Util/CMakeFiles/Qt_Util.dir/Qt_Util_autogen/mocs_compilation.cpp.o"
	cd /home/mzy/Desktop/KdrobotCppLibs-master/build/modules/Qt_Util && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Qt_Util.dir/Qt_Util_autogen/mocs_compilation.cpp.o -c /home/mzy/Desktop/KdrobotCppLibs-master/build/modules/Qt_Util/Qt_Util_autogen/mocs_compilation.cpp

modules/Qt_Util/CMakeFiles/Qt_Util.dir/Qt_Util_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Qt_Util.dir/Qt_Util_autogen/mocs_compilation.cpp.i"
	cd /home/mzy/Desktop/KdrobotCppLibs-master/build/modules/Qt_Util && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mzy/Desktop/KdrobotCppLibs-master/build/modules/Qt_Util/Qt_Util_autogen/mocs_compilation.cpp > CMakeFiles/Qt_Util.dir/Qt_Util_autogen/mocs_compilation.cpp.i

modules/Qt_Util/CMakeFiles/Qt_Util.dir/Qt_Util_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Qt_Util.dir/Qt_Util_autogen/mocs_compilation.cpp.s"
	cd /home/mzy/Desktop/KdrobotCppLibs-master/build/modules/Qt_Util && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mzy/Desktop/KdrobotCppLibs-master/build/modules/Qt_Util/Qt_Util_autogen/mocs_compilation.cpp -o CMakeFiles/Qt_Util.dir/Qt_Util_autogen/mocs_compilation.cpp.s

modules/Qt_Util/CMakeFiles/Qt_Util.dir/source/CRC.cpp.o: modules/Qt_Util/CMakeFiles/Qt_Util.dir/flags.make
modules/Qt_Util/CMakeFiles/Qt_Util.dir/source/CRC.cpp.o: ../modules/Qt_Util/source/CRC.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mzy/Desktop/KdrobotCppLibs-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object modules/Qt_Util/CMakeFiles/Qt_Util.dir/source/CRC.cpp.o"
	cd /home/mzy/Desktop/KdrobotCppLibs-master/build/modules/Qt_Util && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Qt_Util.dir/source/CRC.cpp.o -c /home/mzy/Desktop/KdrobotCppLibs-master/modules/Qt_Util/source/CRC.cpp

modules/Qt_Util/CMakeFiles/Qt_Util.dir/source/CRC.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Qt_Util.dir/source/CRC.cpp.i"
	cd /home/mzy/Desktop/KdrobotCppLibs-master/build/modules/Qt_Util && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mzy/Desktop/KdrobotCppLibs-master/modules/Qt_Util/source/CRC.cpp > CMakeFiles/Qt_Util.dir/source/CRC.cpp.i

modules/Qt_Util/CMakeFiles/Qt_Util.dir/source/CRC.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Qt_Util.dir/source/CRC.cpp.s"
	cd /home/mzy/Desktop/KdrobotCppLibs-master/build/modules/Qt_Util && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mzy/Desktop/KdrobotCppLibs-master/modules/Qt_Util/source/CRC.cpp -o CMakeFiles/Qt_Util.dir/source/CRC.cpp.s

modules/Qt_Util/CMakeFiles/Qt_Util.dir/source/JsonConfig.cpp.o: modules/Qt_Util/CMakeFiles/Qt_Util.dir/flags.make
modules/Qt_Util/CMakeFiles/Qt_Util.dir/source/JsonConfig.cpp.o: ../modules/Qt_Util/source/JsonConfig.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mzy/Desktop/KdrobotCppLibs-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object modules/Qt_Util/CMakeFiles/Qt_Util.dir/source/JsonConfig.cpp.o"
	cd /home/mzy/Desktop/KdrobotCppLibs-master/build/modules/Qt_Util && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Qt_Util.dir/source/JsonConfig.cpp.o -c /home/mzy/Desktop/KdrobotCppLibs-master/modules/Qt_Util/source/JsonConfig.cpp

modules/Qt_Util/CMakeFiles/Qt_Util.dir/source/JsonConfig.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Qt_Util.dir/source/JsonConfig.cpp.i"
	cd /home/mzy/Desktop/KdrobotCppLibs-master/build/modules/Qt_Util && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mzy/Desktop/KdrobotCppLibs-master/modules/Qt_Util/source/JsonConfig.cpp > CMakeFiles/Qt_Util.dir/source/JsonConfig.cpp.i

modules/Qt_Util/CMakeFiles/Qt_Util.dir/source/JsonConfig.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Qt_Util.dir/source/JsonConfig.cpp.s"
	cd /home/mzy/Desktop/KdrobotCppLibs-master/build/modules/Qt_Util && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mzy/Desktop/KdrobotCppLibs-master/modules/Qt_Util/source/JsonConfig.cpp -o CMakeFiles/Qt_Util.dir/source/JsonConfig.cpp.s

modules/Qt_Util/CMakeFiles/Qt_Util.dir/source/MainThread.cpp.o: modules/Qt_Util/CMakeFiles/Qt_Util.dir/flags.make
modules/Qt_Util/CMakeFiles/Qt_Util.dir/source/MainThread.cpp.o: ../modules/Qt_Util/source/MainThread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mzy/Desktop/KdrobotCppLibs-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object modules/Qt_Util/CMakeFiles/Qt_Util.dir/source/MainThread.cpp.o"
	cd /home/mzy/Desktop/KdrobotCppLibs-master/build/modules/Qt_Util && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Qt_Util.dir/source/MainThread.cpp.o -c /home/mzy/Desktop/KdrobotCppLibs-master/modules/Qt_Util/source/MainThread.cpp

modules/Qt_Util/CMakeFiles/Qt_Util.dir/source/MainThread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Qt_Util.dir/source/MainThread.cpp.i"
	cd /home/mzy/Desktop/KdrobotCppLibs-master/build/modules/Qt_Util && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mzy/Desktop/KdrobotCppLibs-master/modules/Qt_Util/source/MainThread.cpp > CMakeFiles/Qt_Util.dir/source/MainThread.cpp.i

modules/Qt_Util/CMakeFiles/Qt_Util.dir/source/MainThread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Qt_Util.dir/source/MainThread.cpp.s"
	cd /home/mzy/Desktop/KdrobotCppLibs-master/build/modules/Qt_Util && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mzy/Desktop/KdrobotCppLibs-master/modules/Qt_Util/source/MainThread.cpp -o CMakeFiles/Qt_Util.dir/source/MainThread.cpp.s

# Object files for target Qt_Util
Qt_Util_OBJECTS = \
"CMakeFiles/Qt_Util.dir/Qt_Util_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/Qt_Util.dir/source/CRC.cpp.o" \
"CMakeFiles/Qt_Util.dir/source/JsonConfig.cpp.o" \
"CMakeFiles/Qt_Util.dir/source/MainThread.cpp.o"

# External object files for target Qt_Util
Qt_Util_EXTERNAL_OBJECTS =

modules/Qt_Util/libQt_Util.a: modules/Qt_Util/CMakeFiles/Qt_Util.dir/Qt_Util_autogen/mocs_compilation.cpp.o
modules/Qt_Util/libQt_Util.a: modules/Qt_Util/CMakeFiles/Qt_Util.dir/source/CRC.cpp.o
modules/Qt_Util/libQt_Util.a: modules/Qt_Util/CMakeFiles/Qt_Util.dir/source/JsonConfig.cpp.o
modules/Qt_Util/libQt_Util.a: modules/Qt_Util/CMakeFiles/Qt_Util.dir/source/MainThread.cpp.o
modules/Qt_Util/libQt_Util.a: modules/Qt_Util/CMakeFiles/Qt_Util.dir/build.make
modules/Qt_Util/libQt_Util.a: modules/Qt_Util/CMakeFiles/Qt_Util.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mzy/Desktop/KdrobotCppLibs-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX static library libQt_Util.a"
	cd /home/mzy/Desktop/KdrobotCppLibs-master/build/modules/Qt_Util && $(CMAKE_COMMAND) -P CMakeFiles/Qt_Util.dir/cmake_clean_target.cmake
	cd /home/mzy/Desktop/KdrobotCppLibs-master/build/modules/Qt_Util && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Qt_Util.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
modules/Qt_Util/CMakeFiles/Qt_Util.dir/build: modules/Qt_Util/libQt_Util.a

.PHONY : modules/Qt_Util/CMakeFiles/Qt_Util.dir/build

modules/Qt_Util/CMakeFiles/Qt_Util.dir/clean:
	cd /home/mzy/Desktop/KdrobotCppLibs-master/build/modules/Qt_Util && $(CMAKE_COMMAND) -P CMakeFiles/Qt_Util.dir/cmake_clean.cmake
.PHONY : modules/Qt_Util/CMakeFiles/Qt_Util.dir/clean

modules/Qt_Util/CMakeFiles/Qt_Util.dir/depend:
	cd /home/mzy/Desktop/KdrobotCppLibs-master/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mzy/Desktop/KdrobotCppLibs-master /home/mzy/Desktop/KdrobotCppLibs-master/modules/Qt_Util /home/mzy/Desktop/KdrobotCppLibs-master/build /home/mzy/Desktop/KdrobotCppLibs-master/build/modules/Qt_Util /home/mzy/Desktop/KdrobotCppLibs-master/build/modules/Qt_Util/CMakeFiles/Qt_Util.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : modules/Qt_Util/CMakeFiles/Qt_Util.dir/depend

