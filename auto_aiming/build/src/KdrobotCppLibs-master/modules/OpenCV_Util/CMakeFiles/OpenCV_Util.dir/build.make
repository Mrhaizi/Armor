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
include src/KdrobotCppLibs-master/modules/OpenCV_Util/CMakeFiles/OpenCV_Util.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/KdrobotCppLibs-master/modules/OpenCV_Util/CMakeFiles/OpenCV_Util.dir/compiler_depend.make

# Include the progress variables for this target.
include src/KdrobotCppLibs-master/modules/OpenCV_Util/CMakeFiles/OpenCV_Util.dir/progress.make

# Include the compile flags for this target's objects.
include src/KdrobotCppLibs-master/modules/OpenCV_Util/CMakeFiles/OpenCV_Util.dir/flags.make

src/KdrobotCppLibs-master/modules/OpenCV_Util/CMakeFiles/OpenCV_Util.dir/source/OpenCV_Util.cpp.o: src/KdrobotCppLibs-master/modules/OpenCV_Util/CMakeFiles/OpenCV_Util.dir/flags.make
src/KdrobotCppLibs-master/modules/OpenCV_Util/CMakeFiles/OpenCV_Util.dir/source/OpenCV_Util.cpp.o: ../src/KdrobotCppLibs-master/modules/OpenCV_Util/source/OpenCV_Util.cpp
src/KdrobotCppLibs-master/modules/OpenCV_Util/CMakeFiles/OpenCV_Util.dir/source/OpenCV_Util.cpp.o: src/KdrobotCppLibs-master/modules/OpenCV_Util/CMakeFiles/OpenCV_Util.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mayuqi/桌面/Armor/auto_aiming/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/KdrobotCppLibs-master/modules/OpenCV_Util/CMakeFiles/OpenCV_Util.dir/source/OpenCV_Util.cpp.o"
	cd /home/mayuqi/桌面/Armor/auto_aiming/build/src/KdrobotCppLibs-master/modules/OpenCV_Util && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/KdrobotCppLibs-master/modules/OpenCV_Util/CMakeFiles/OpenCV_Util.dir/source/OpenCV_Util.cpp.o -MF CMakeFiles/OpenCV_Util.dir/source/OpenCV_Util.cpp.o.d -o CMakeFiles/OpenCV_Util.dir/source/OpenCV_Util.cpp.o -c /home/mayuqi/桌面/Armor/auto_aiming/src/KdrobotCppLibs-master/modules/OpenCV_Util/source/OpenCV_Util.cpp

src/KdrobotCppLibs-master/modules/OpenCV_Util/CMakeFiles/OpenCV_Util.dir/source/OpenCV_Util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenCV_Util.dir/source/OpenCV_Util.cpp.i"
	cd /home/mayuqi/桌面/Armor/auto_aiming/build/src/KdrobotCppLibs-master/modules/OpenCV_Util && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mayuqi/桌面/Armor/auto_aiming/src/KdrobotCppLibs-master/modules/OpenCV_Util/source/OpenCV_Util.cpp > CMakeFiles/OpenCV_Util.dir/source/OpenCV_Util.cpp.i

src/KdrobotCppLibs-master/modules/OpenCV_Util/CMakeFiles/OpenCV_Util.dir/source/OpenCV_Util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenCV_Util.dir/source/OpenCV_Util.cpp.s"
	cd /home/mayuqi/桌面/Armor/auto_aiming/build/src/KdrobotCppLibs-master/modules/OpenCV_Util && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mayuqi/桌面/Armor/auto_aiming/src/KdrobotCppLibs-master/modules/OpenCV_Util/source/OpenCV_Util.cpp -o CMakeFiles/OpenCV_Util.dir/source/OpenCV_Util.cpp.s

src/KdrobotCppLibs-master/modules/OpenCV_Util/CMakeFiles/OpenCV_Util.dir/source/PNP_Calculate.cpp.o: src/KdrobotCppLibs-master/modules/OpenCV_Util/CMakeFiles/OpenCV_Util.dir/flags.make
src/KdrobotCppLibs-master/modules/OpenCV_Util/CMakeFiles/OpenCV_Util.dir/source/PNP_Calculate.cpp.o: ../src/KdrobotCppLibs-master/modules/OpenCV_Util/source/PNP_Calculate.cpp
src/KdrobotCppLibs-master/modules/OpenCV_Util/CMakeFiles/OpenCV_Util.dir/source/PNP_Calculate.cpp.o: src/KdrobotCppLibs-master/modules/OpenCV_Util/CMakeFiles/OpenCV_Util.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mayuqi/桌面/Armor/auto_aiming/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/KdrobotCppLibs-master/modules/OpenCV_Util/CMakeFiles/OpenCV_Util.dir/source/PNP_Calculate.cpp.o"
	cd /home/mayuqi/桌面/Armor/auto_aiming/build/src/KdrobotCppLibs-master/modules/OpenCV_Util && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/KdrobotCppLibs-master/modules/OpenCV_Util/CMakeFiles/OpenCV_Util.dir/source/PNP_Calculate.cpp.o -MF CMakeFiles/OpenCV_Util.dir/source/PNP_Calculate.cpp.o.d -o CMakeFiles/OpenCV_Util.dir/source/PNP_Calculate.cpp.o -c /home/mayuqi/桌面/Armor/auto_aiming/src/KdrobotCppLibs-master/modules/OpenCV_Util/source/PNP_Calculate.cpp

src/KdrobotCppLibs-master/modules/OpenCV_Util/CMakeFiles/OpenCV_Util.dir/source/PNP_Calculate.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenCV_Util.dir/source/PNP_Calculate.cpp.i"
	cd /home/mayuqi/桌面/Armor/auto_aiming/build/src/KdrobotCppLibs-master/modules/OpenCV_Util && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mayuqi/桌面/Armor/auto_aiming/src/KdrobotCppLibs-master/modules/OpenCV_Util/source/PNP_Calculate.cpp > CMakeFiles/OpenCV_Util.dir/source/PNP_Calculate.cpp.i

src/KdrobotCppLibs-master/modules/OpenCV_Util/CMakeFiles/OpenCV_Util.dir/source/PNP_Calculate.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenCV_Util.dir/source/PNP_Calculate.cpp.s"
	cd /home/mayuqi/桌面/Armor/auto_aiming/build/src/KdrobotCppLibs-master/modules/OpenCV_Util && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mayuqi/桌面/Armor/auto_aiming/src/KdrobotCppLibs-master/modules/OpenCV_Util/source/PNP_Calculate.cpp -o CMakeFiles/OpenCV_Util.dir/source/PNP_Calculate.cpp.s

src/KdrobotCppLibs-master/modules/OpenCV_Util/CMakeFiles/OpenCV_Util.dir/source/coordinate.cpp.o: src/KdrobotCppLibs-master/modules/OpenCV_Util/CMakeFiles/OpenCV_Util.dir/flags.make
src/KdrobotCppLibs-master/modules/OpenCV_Util/CMakeFiles/OpenCV_Util.dir/source/coordinate.cpp.o: ../src/KdrobotCppLibs-master/modules/OpenCV_Util/source/coordinate.cpp
src/KdrobotCppLibs-master/modules/OpenCV_Util/CMakeFiles/OpenCV_Util.dir/source/coordinate.cpp.o: src/KdrobotCppLibs-master/modules/OpenCV_Util/CMakeFiles/OpenCV_Util.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mayuqi/桌面/Armor/auto_aiming/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/KdrobotCppLibs-master/modules/OpenCV_Util/CMakeFiles/OpenCV_Util.dir/source/coordinate.cpp.o"
	cd /home/mayuqi/桌面/Armor/auto_aiming/build/src/KdrobotCppLibs-master/modules/OpenCV_Util && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/KdrobotCppLibs-master/modules/OpenCV_Util/CMakeFiles/OpenCV_Util.dir/source/coordinate.cpp.o -MF CMakeFiles/OpenCV_Util.dir/source/coordinate.cpp.o.d -o CMakeFiles/OpenCV_Util.dir/source/coordinate.cpp.o -c /home/mayuqi/桌面/Armor/auto_aiming/src/KdrobotCppLibs-master/modules/OpenCV_Util/source/coordinate.cpp

src/KdrobotCppLibs-master/modules/OpenCV_Util/CMakeFiles/OpenCV_Util.dir/source/coordinate.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenCV_Util.dir/source/coordinate.cpp.i"
	cd /home/mayuqi/桌面/Armor/auto_aiming/build/src/KdrobotCppLibs-master/modules/OpenCV_Util && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mayuqi/桌面/Armor/auto_aiming/src/KdrobotCppLibs-master/modules/OpenCV_Util/source/coordinate.cpp > CMakeFiles/OpenCV_Util.dir/source/coordinate.cpp.i

src/KdrobotCppLibs-master/modules/OpenCV_Util/CMakeFiles/OpenCV_Util.dir/source/coordinate.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenCV_Util.dir/source/coordinate.cpp.s"
	cd /home/mayuqi/桌面/Armor/auto_aiming/build/src/KdrobotCppLibs-master/modules/OpenCV_Util && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mayuqi/桌面/Armor/auto_aiming/src/KdrobotCppLibs-master/modules/OpenCV_Util/source/coordinate.cpp -o CMakeFiles/OpenCV_Util.dir/source/coordinate.cpp.s

# Object files for target OpenCV_Util
OpenCV_Util_OBJECTS = \
"CMakeFiles/OpenCV_Util.dir/source/OpenCV_Util.cpp.o" \
"CMakeFiles/OpenCV_Util.dir/source/PNP_Calculate.cpp.o" \
"CMakeFiles/OpenCV_Util.dir/source/coordinate.cpp.o"

# External object files for target OpenCV_Util
OpenCV_Util_EXTERNAL_OBJECTS =

src/KdrobotCppLibs-master/modules/OpenCV_Util/libOpenCV_Util.a: src/KdrobotCppLibs-master/modules/OpenCV_Util/CMakeFiles/OpenCV_Util.dir/source/OpenCV_Util.cpp.o
src/KdrobotCppLibs-master/modules/OpenCV_Util/libOpenCV_Util.a: src/KdrobotCppLibs-master/modules/OpenCV_Util/CMakeFiles/OpenCV_Util.dir/source/PNP_Calculate.cpp.o
src/KdrobotCppLibs-master/modules/OpenCV_Util/libOpenCV_Util.a: src/KdrobotCppLibs-master/modules/OpenCV_Util/CMakeFiles/OpenCV_Util.dir/source/coordinate.cpp.o
src/KdrobotCppLibs-master/modules/OpenCV_Util/libOpenCV_Util.a: src/KdrobotCppLibs-master/modules/OpenCV_Util/CMakeFiles/OpenCV_Util.dir/build.make
src/KdrobotCppLibs-master/modules/OpenCV_Util/libOpenCV_Util.a: src/KdrobotCppLibs-master/modules/OpenCV_Util/CMakeFiles/OpenCV_Util.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mayuqi/桌面/Armor/auto_aiming/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libOpenCV_Util.a"
	cd /home/mayuqi/桌面/Armor/auto_aiming/build/src/KdrobotCppLibs-master/modules/OpenCV_Util && $(CMAKE_COMMAND) -P CMakeFiles/OpenCV_Util.dir/cmake_clean_target.cmake
	cd /home/mayuqi/桌面/Armor/auto_aiming/build/src/KdrobotCppLibs-master/modules/OpenCV_Util && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/OpenCV_Util.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/KdrobotCppLibs-master/modules/OpenCV_Util/CMakeFiles/OpenCV_Util.dir/build: src/KdrobotCppLibs-master/modules/OpenCV_Util/libOpenCV_Util.a
.PHONY : src/KdrobotCppLibs-master/modules/OpenCV_Util/CMakeFiles/OpenCV_Util.dir/build

src/KdrobotCppLibs-master/modules/OpenCV_Util/CMakeFiles/OpenCV_Util.dir/clean:
	cd /home/mayuqi/桌面/Armor/auto_aiming/build/src/KdrobotCppLibs-master/modules/OpenCV_Util && $(CMAKE_COMMAND) -P CMakeFiles/OpenCV_Util.dir/cmake_clean.cmake
.PHONY : src/KdrobotCppLibs-master/modules/OpenCV_Util/CMakeFiles/OpenCV_Util.dir/clean

src/KdrobotCppLibs-master/modules/OpenCV_Util/CMakeFiles/OpenCV_Util.dir/depend:
	cd /home/mayuqi/桌面/Armor/auto_aiming/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mayuqi/桌面/Armor/auto_aiming /home/mayuqi/桌面/Armor/auto_aiming/src/KdrobotCppLibs-master/modules/OpenCV_Util /home/mayuqi/桌面/Armor/auto_aiming/build /home/mayuqi/桌面/Armor/auto_aiming/build/src/KdrobotCppLibs-master/modules/OpenCV_Util /home/mayuqi/桌面/Armor/auto_aiming/build/src/KdrobotCppLibs-master/modules/OpenCV_Util/CMakeFiles/OpenCV_Util.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/KdrobotCppLibs-master/modules/OpenCV_Util/CMakeFiles/OpenCV_Util.dir/depend

