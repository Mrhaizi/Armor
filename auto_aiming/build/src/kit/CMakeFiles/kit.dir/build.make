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
include src/kit/CMakeFiles/kit.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/kit/CMakeFiles/kit.dir/compiler_depend.make

# Include the progress variables for this target.
include src/kit/CMakeFiles/kit.dir/progress.make

# Include the compile flags for this target's objects.
include src/kit/CMakeFiles/kit.dir/flags.make

src/kit/CMakeFiles/kit.dir/src/kit.cpp.o: src/kit/CMakeFiles/kit.dir/flags.make
src/kit/CMakeFiles/kit.dir/src/kit.cpp.o: ../src/kit/src/kit.cpp
src/kit/CMakeFiles/kit.dir/src/kit.cpp.o: src/kit/CMakeFiles/kit.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mayuqi/桌面/Armor/auto_aiming/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/kit/CMakeFiles/kit.dir/src/kit.cpp.o"
	cd /home/mayuqi/桌面/Armor/auto_aiming/build/src/kit && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/kit/CMakeFiles/kit.dir/src/kit.cpp.o -MF CMakeFiles/kit.dir/src/kit.cpp.o.d -o CMakeFiles/kit.dir/src/kit.cpp.o -c /home/mayuqi/桌面/Armor/auto_aiming/src/kit/src/kit.cpp

src/kit/CMakeFiles/kit.dir/src/kit.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kit.dir/src/kit.cpp.i"
	cd /home/mayuqi/桌面/Armor/auto_aiming/build/src/kit && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mayuqi/桌面/Armor/auto_aiming/src/kit/src/kit.cpp > CMakeFiles/kit.dir/src/kit.cpp.i

src/kit/CMakeFiles/kit.dir/src/kit.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kit.dir/src/kit.cpp.s"
	cd /home/mayuqi/桌面/Armor/auto_aiming/build/src/kit && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mayuqi/桌面/Armor/auto_aiming/src/kit/src/kit.cpp -o CMakeFiles/kit.dir/src/kit.cpp.s

# Object files for target kit
kit_OBJECTS = \
"CMakeFiles/kit.dir/src/kit.cpp.o"

# External object files for target kit
kit_EXTERNAL_OBJECTS =

src/kit/libkit.a: src/kit/CMakeFiles/kit.dir/src/kit.cpp.o
src/kit/libkit.a: src/kit/CMakeFiles/kit.dir/build.make
src/kit/libkit.a: src/kit/CMakeFiles/kit.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mayuqi/桌面/Armor/auto_aiming/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libkit.a"
	cd /home/mayuqi/桌面/Armor/auto_aiming/build/src/kit && $(CMAKE_COMMAND) -P CMakeFiles/kit.dir/cmake_clean_target.cmake
	cd /home/mayuqi/桌面/Armor/auto_aiming/build/src/kit && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/kit.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/kit/CMakeFiles/kit.dir/build: src/kit/libkit.a
.PHONY : src/kit/CMakeFiles/kit.dir/build

src/kit/CMakeFiles/kit.dir/clean:
	cd /home/mayuqi/桌面/Armor/auto_aiming/build/src/kit && $(CMAKE_COMMAND) -P CMakeFiles/kit.dir/cmake_clean.cmake
.PHONY : src/kit/CMakeFiles/kit.dir/clean

src/kit/CMakeFiles/kit.dir/depend:
	cd /home/mayuqi/桌面/Armor/auto_aiming/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mayuqi/桌面/Armor/auto_aiming /home/mayuqi/桌面/Armor/auto_aiming/src/kit /home/mayuqi/桌面/Armor/auto_aiming/build /home/mayuqi/桌面/Armor/auto_aiming/build/src/kit /home/mayuqi/桌面/Armor/auto_aiming/build/src/kit/CMakeFiles/kit.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/kit/CMakeFiles/kit.dir/depend

