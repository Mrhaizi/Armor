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
include src/KdrobotCppLibs-master/modules/loggerFactory/CMakeFiles/loggerFactory.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/KdrobotCppLibs-master/modules/loggerFactory/CMakeFiles/loggerFactory.dir/compiler_depend.make

# Include the progress variables for this target.
include src/KdrobotCppLibs-master/modules/loggerFactory/CMakeFiles/loggerFactory.dir/progress.make

# Include the compile flags for this target's objects.
include src/KdrobotCppLibs-master/modules/loggerFactory/CMakeFiles/loggerFactory.dir/flags.make

src/KdrobotCppLibs-master/modules/loggerFactory/CMakeFiles/loggerFactory.dir/source/spdlogger.cpp.o: src/KdrobotCppLibs-master/modules/loggerFactory/CMakeFiles/loggerFactory.dir/flags.make
src/KdrobotCppLibs-master/modules/loggerFactory/CMakeFiles/loggerFactory.dir/source/spdlogger.cpp.o: ../src/KdrobotCppLibs-master/modules/loggerFactory/source/spdlogger.cpp
src/KdrobotCppLibs-master/modules/loggerFactory/CMakeFiles/loggerFactory.dir/source/spdlogger.cpp.o: src/KdrobotCppLibs-master/modules/loggerFactory/CMakeFiles/loggerFactory.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mayuqi/桌面/Armor/auto_aiming/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/KdrobotCppLibs-master/modules/loggerFactory/CMakeFiles/loggerFactory.dir/source/spdlogger.cpp.o"
	cd /home/mayuqi/桌面/Armor/auto_aiming/build/src/KdrobotCppLibs-master/modules/loggerFactory && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/KdrobotCppLibs-master/modules/loggerFactory/CMakeFiles/loggerFactory.dir/source/spdlogger.cpp.o -MF CMakeFiles/loggerFactory.dir/source/spdlogger.cpp.o.d -o CMakeFiles/loggerFactory.dir/source/spdlogger.cpp.o -c /home/mayuqi/桌面/Armor/auto_aiming/src/KdrobotCppLibs-master/modules/loggerFactory/source/spdlogger.cpp

src/KdrobotCppLibs-master/modules/loggerFactory/CMakeFiles/loggerFactory.dir/source/spdlogger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/loggerFactory.dir/source/spdlogger.cpp.i"
	cd /home/mayuqi/桌面/Armor/auto_aiming/build/src/KdrobotCppLibs-master/modules/loggerFactory && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mayuqi/桌面/Armor/auto_aiming/src/KdrobotCppLibs-master/modules/loggerFactory/source/spdlogger.cpp > CMakeFiles/loggerFactory.dir/source/spdlogger.cpp.i

src/KdrobotCppLibs-master/modules/loggerFactory/CMakeFiles/loggerFactory.dir/source/spdlogger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/loggerFactory.dir/source/spdlogger.cpp.s"
	cd /home/mayuqi/桌面/Armor/auto_aiming/build/src/KdrobotCppLibs-master/modules/loggerFactory && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mayuqi/桌面/Armor/auto_aiming/src/KdrobotCppLibs-master/modules/loggerFactory/source/spdlogger.cpp -o CMakeFiles/loggerFactory.dir/source/spdlogger.cpp.s

src/KdrobotCppLibs-master/modules/loggerFactory/CMakeFiles/loggerFactory.dir/source/BackTrace.cpp.o: src/KdrobotCppLibs-master/modules/loggerFactory/CMakeFiles/loggerFactory.dir/flags.make
src/KdrobotCppLibs-master/modules/loggerFactory/CMakeFiles/loggerFactory.dir/source/BackTrace.cpp.o: ../src/KdrobotCppLibs-master/modules/loggerFactory/source/BackTrace.cpp
src/KdrobotCppLibs-master/modules/loggerFactory/CMakeFiles/loggerFactory.dir/source/BackTrace.cpp.o: src/KdrobotCppLibs-master/modules/loggerFactory/CMakeFiles/loggerFactory.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mayuqi/桌面/Armor/auto_aiming/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/KdrobotCppLibs-master/modules/loggerFactory/CMakeFiles/loggerFactory.dir/source/BackTrace.cpp.o"
	cd /home/mayuqi/桌面/Armor/auto_aiming/build/src/KdrobotCppLibs-master/modules/loggerFactory && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/KdrobotCppLibs-master/modules/loggerFactory/CMakeFiles/loggerFactory.dir/source/BackTrace.cpp.o -MF CMakeFiles/loggerFactory.dir/source/BackTrace.cpp.o.d -o CMakeFiles/loggerFactory.dir/source/BackTrace.cpp.o -c /home/mayuqi/桌面/Armor/auto_aiming/src/KdrobotCppLibs-master/modules/loggerFactory/source/BackTrace.cpp

src/KdrobotCppLibs-master/modules/loggerFactory/CMakeFiles/loggerFactory.dir/source/BackTrace.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/loggerFactory.dir/source/BackTrace.cpp.i"
	cd /home/mayuqi/桌面/Armor/auto_aiming/build/src/KdrobotCppLibs-master/modules/loggerFactory && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mayuqi/桌面/Armor/auto_aiming/src/KdrobotCppLibs-master/modules/loggerFactory/source/BackTrace.cpp > CMakeFiles/loggerFactory.dir/source/BackTrace.cpp.i

src/KdrobotCppLibs-master/modules/loggerFactory/CMakeFiles/loggerFactory.dir/source/BackTrace.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/loggerFactory.dir/source/BackTrace.cpp.s"
	cd /home/mayuqi/桌面/Armor/auto_aiming/build/src/KdrobotCppLibs-master/modules/loggerFactory && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mayuqi/桌面/Armor/auto_aiming/src/KdrobotCppLibs-master/modules/loggerFactory/source/BackTrace.cpp -o CMakeFiles/loggerFactory.dir/source/BackTrace.cpp.s

src/KdrobotCppLibs-master/modules/loggerFactory/CMakeFiles/loggerFactory.dir/source/spdUtil.cpp.o: src/KdrobotCppLibs-master/modules/loggerFactory/CMakeFiles/loggerFactory.dir/flags.make
src/KdrobotCppLibs-master/modules/loggerFactory/CMakeFiles/loggerFactory.dir/source/spdUtil.cpp.o: ../src/KdrobotCppLibs-master/modules/loggerFactory/source/spdUtil.cpp
src/KdrobotCppLibs-master/modules/loggerFactory/CMakeFiles/loggerFactory.dir/source/spdUtil.cpp.o: src/KdrobotCppLibs-master/modules/loggerFactory/CMakeFiles/loggerFactory.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mayuqi/桌面/Armor/auto_aiming/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/KdrobotCppLibs-master/modules/loggerFactory/CMakeFiles/loggerFactory.dir/source/spdUtil.cpp.o"
	cd /home/mayuqi/桌面/Armor/auto_aiming/build/src/KdrobotCppLibs-master/modules/loggerFactory && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/KdrobotCppLibs-master/modules/loggerFactory/CMakeFiles/loggerFactory.dir/source/spdUtil.cpp.o -MF CMakeFiles/loggerFactory.dir/source/spdUtil.cpp.o.d -o CMakeFiles/loggerFactory.dir/source/spdUtil.cpp.o -c /home/mayuqi/桌面/Armor/auto_aiming/src/KdrobotCppLibs-master/modules/loggerFactory/source/spdUtil.cpp

src/KdrobotCppLibs-master/modules/loggerFactory/CMakeFiles/loggerFactory.dir/source/spdUtil.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/loggerFactory.dir/source/spdUtil.cpp.i"
	cd /home/mayuqi/桌面/Armor/auto_aiming/build/src/KdrobotCppLibs-master/modules/loggerFactory && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mayuqi/桌面/Armor/auto_aiming/src/KdrobotCppLibs-master/modules/loggerFactory/source/spdUtil.cpp > CMakeFiles/loggerFactory.dir/source/spdUtil.cpp.i

src/KdrobotCppLibs-master/modules/loggerFactory/CMakeFiles/loggerFactory.dir/source/spdUtil.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/loggerFactory.dir/source/spdUtil.cpp.s"
	cd /home/mayuqi/桌面/Armor/auto_aiming/build/src/KdrobotCppLibs-master/modules/loggerFactory && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mayuqi/桌面/Armor/auto_aiming/src/KdrobotCppLibs-master/modules/loggerFactory/source/spdUtil.cpp -o CMakeFiles/loggerFactory.dir/source/spdUtil.cpp.s

# Object files for target loggerFactory
loggerFactory_OBJECTS = \
"CMakeFiles/loggerFactory.dir/source/spdlogger.cpp.o" \
"CMakeFiles/loggerFactory.dir/source/BackTrace.cpp.o" \
"CMakeFiles/loggerFactory.dir/source/spdUtil.cpp.o"

# External object files for target loggerFactory
loggerFactory_EXTERNAL_OBJECTS =

src/KdrobotCppLibs-master/modules/loggerFactory/libloggerFactory.a: src/KdrobotCppLibs-master/modules/loggerFactory/CMakeFiles/loggerFactory.dir/source/spdlogger.cpp.o
src/KdrobotCppLibs-master/modules/loggerFactory/libloggerFactory.a: src/KdrobotCppLibs-master/modules/loggerFactory/CMakeFiles/loggerFactory.dir/source/BackTrace.cpp.o
src/KdrobotCppLibs-master/modules/loggerFactory/libloggerFactory.a: src/KdrobotCppLibs-master/modules/loggerFactory/CMakeFiles/loggerFactory.dir/source/spdUtil.cpp.o
src/KdrobotCppLibs-master/modules/loggerFactory/libloggerFactory.a: src/KdrobotCppLibs-master/modules/loggerFactory/CMakeFiles/loggerFactory.dir/build.make
src/KdrobotCppLibs-master/modules/loggerFactory/libloggerFactory.a: src/KdrobotCppLibs-master/modules/loggerFactory/CMakeFiles/loggerFactory.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mayuqi/桌面/Armor/auto_aiming/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libloggerFactory.a"
	cd /home/mayuqi/桌面/Armor/auto_aiming/build/src/KdrobotCppLibs-master/modules/loggerFactory && $(CMAKE_COMMAND) -P CMakeFiles/loggerFactory.dir/cmake_clean_target.cmake
	cd /home/mayuqi/桌面/Armor/auto_aiming/build/src/KdrobotCppLibs-master/modules/loggerFactory && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/loggerFactory.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/KdrobotCppLibs-master/modules/loggerFactory/CMakeFiles/loggerFactory.dir/build: src/KdrobotCppLibs-master/modules/loggerFactory/libloggerFactory.a
.PHONY : src/KdrobotCppLibs-master/modules/loggerFactory/CMakeFiles/loggerFactory.dir/build

src/KdrobotCppLibs-master/modules/loggerFactory/CMakeFiles/loggerFactory.dir/clean:
	cd /home/mayuqi/桌面/Armor/auto_aiming/build/src/KdrobotCppLibs-master/modules/loggerFactory && $(CMAKE_COMMAND) -P CMakeFiles/loggerFactory.dir/cmake_clean.cmake
.PHONY : src/KdrobotCppLibs-master/modules/loggerFactory/CMakeFiles/loggerFactory.dir/clean

src/KdrobotCppLibs-master/modules/loggerFactory/CMakeFiles/loggerFactory.dir/depend:
	cd /home/mayuqi/桌面/Armor/auto_aiming/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mayuqi/桌面/Armor/auto_aiming /home/mayuqi/桌面/Armor/auto_aiming/src/KdrobotCppLibs-master/modules/loggerFactory /home/mayuqi/桌面/Armor/auto_aiming/build /home/mayuqi/桌面/Armor/auto_aiming/build/src/KdrobotCppLibs-master/modules/loggerFactory /home/mayuqi/桌面/Armor/auto_aiming/build/src/KdrobotCppLibs-master/modules/loggerFactory/CMakeFiles/loggerFactory.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/KdrobotCppLibs-master/modules/loggerFactory/CMakeFiles/loggerFactory.dir/depend

