# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mayuqi/桌面/Armor/auto_aiming

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mayuqi/桌面/Armor/auto_aiming/build

# Include any dependencies generated for this target.
include src/openvino_infer/CMakeFiles/openvino.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/openvino_infer/CMakeFiles/openvino.dir/compiler_depend.make

# Include the progress variables for this target.
include src/openvino_infer/CMakeFiles/openvino.dir/progress.make

# Include the compile flags for this target's objects.
include src/openvino_infer/CMakeFiles/openvino.dir/flags.make

src/openvino_infer/CMakeFiles/openvino.dir/src/openvino.cpp.o: src/openvino_infer/CMakeFiles/openvino.dir/flags.make
src/openvino_infer/CMakeFiles/openvino.dir/src/openvino.cpp.o: ../src/openvino_infer/src/openvino.cpp
src/openvino_infer/CMakeFiles/openvino.dir/src/openvino.cpp.o: src/openvino_infer/CMakeFiles/openvino.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mayuqi/桌面/Armor/auto_aiming/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/openvino_infer/CMakeFiles/openvino.dir/src/openvino.cpp.o"
	cd /home/mayuqi/桌面/Armor/auto_aiming/build/src/openvino_infer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/openvino_infer/CMakeFiles/openvino.dir/src/openvino.cpp.o -MF CMakeFiles/openvino.dir/src/openvino.cpp.o.d -o CMakeFiles/openvino.dir/src/openvino.cpp.o -c /home/mayuqi/桌面/Armor/auto_aiming/src/openvino_infer/src/openvino.cpp

src/openvino_infer/CMakeFiles/openvino.dir/src/openvino.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/openvino.dir/src/openvino.cpp.i"
	cd /home/mayuqi/桌面/Armor/auto_aiming/build/src/openvino_infer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mayuqi/桌面/Armor/auto_aiming/src/openvino_infer/src/openvino.cpp > CMakeFiles/openvino.dir/src/openvino.cpp.i

src/openvino_infer/CMakeFiles/openvino.dir/src/openvino.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/openvino.dir/src/openvino.cpp.s"
	cd /home/mayuqi/桌面/Armor/auto_aiming/build/src/openvino_infer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mayuqi/桌面/Armor/auto_aiming/src/openvino_infer/src/openvino.cpp -o CMakeFiles/openvino.dir/src/openvino.cpp.s

# Object files for target openvino
openvino_OBJECTS = \
"CMakeFiles/openvino.dir/src/openvino.cpp.o"

# External object files for target openvino
openvino_EXTERNAL_OBJECTS =

src/openvino_infer/libopenvino.a: src/openvino_infer/CMakeFiles/openvino.dir/src/openvino.cpp.o
src/openvino_infer/libopenvino.a: src/openvino_infer/CMakeFiles/openvino.dir/build.make
src/openvino_infer/libopenvino.a: src/openvino_infer/CMakeFiles/openvino.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mayuqi/桌面/Armor/auto_aiming/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libopenvino.a"
	cd /home/mayuqi/桌面/Armor/auto_aiming/build/src/openvino_infer && $(CMAKE_COMMAND) -P CMakeFiles/openvino.dir/cmake_clean_target.cmake
	cd /home/mayuqi/桌面/Armor/auto_aiming/build/src/openvino_infer && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/openvino.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/openvino_infer/CMakeFiles/openvino.dir/build: src/openvino_infer/libopenvino.a
.PHONY : src/openvino_infer/CMakeFiles/openvino.dir/build

src/openvino_infer/CMakeFiles/openvino.dir/clean:
	cd /home/mayuqi/桌面/Armor/auto_aiming/build/src/openvino_infer && $(CMAKE_COMMAND) -P CMakeFiles/openvino.dir/cmake_clean.cmake
.PHONY : src/openvino_infer/CMakeFiles/openvino.dir/clean

src/openvino_infer/CMakeFiles/openvino.dir/depend:
	cd /home/mayuqi/桌面/Armor/auto_aiming/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mayuqi/桌面/Armor/auto_aiming /home/mayuqi/桌面/Armor/auto_aiming/src/openvino_infer /home/mayuqi/桌面/Armor/auto_aiming/build /home/mayuqi/桌面/Armor/auto_aiming/build/src/openvino_infer /home/mayuqi/桌面/Armor/auto_aiming/build/src/openvino_infer/CMakeFiles/openvino.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/openvino_infer/CMakeFiles/openvino.dir/depend

