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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.22.3/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.22.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/jianshuzhao/Github/parasail-sys/parasail

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jianshuzhao/Github/parasail-sys/parasail/build

# Include any dependencies generated for this target.
include CMakeFiles/ssw.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ssw.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ssw.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ssw.dir/flags.make

CMakeFiles/ssw.dir/cmake/ssw_dummy.c.o: CMakeFiles/ssw.dir/flags.make
CMakeFiles/ssw.dir/cmake/ssw_dummy.c.o: ../cmake/ssw_dummy.c
CMakeFiles/ssw.dir/cmake/ssw_dummy.c.o: CMakeFiles/ssw.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jianshuzhao/Github/parasail-sys/parasail/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ssw.dir/cmake/ssw_dummy.c.o"
	/usr/local/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ssw.dir/cmake/ssw_dummy.c.o -MF CMakeFiles/ssw.dir/cmake/ssw_dummy.c.o.d -o CMakeFiles/ssw.dir/cmake/ssw_dummy.c.o -c /Users/jianshuzhao/Github/parasail-sys/parasail/cmake/ssw_dummy.c

CMakeFiles/ssw.dir/cmake/ssw_dummy.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ssw.dir/cmake/ssw_dummy.c.i"
	/usr/local/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jianshuzhao/Github/parasail-sys/parasail/cmake/ssw_dummy.c > CMakeFiles/ssw.dir/cmake/ssw_dummy.c.i

CMakeFiles/ssw.dir/cmake/ssw_dummy.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ssw.dir/cmake/ssw_dummy.c.s"
	/usr/local/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jianshuzhao/Github/parasail-sys/parasail/cmake/ssw_dummy.c -o CMakeFiles/ssw.dir/cmake/ssw_dummy.c.s

ssw: CMakeFiles/ssw.dir/cmake/ssw_dummy.c.o
ssw: CMakeFiles/ssw.dir/build.make
.PHONY : ssw

# Rule to build all files generated by this target.
CMakeFiles/ssw.dir/build: ssw
.PHONY : CMakeFiles/ssw.dir/build

CMakeFiles/ssw.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ssw.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ssw.dir/clean

CMakeFiles/ssw.dir/depend:
	cd /Users/jianshuzhao/Github/parasail-sys/parasail/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jianshuzhao/Github/parasail-sys/parasail /Users/jianshuzhao/Github/parasail-sys/parasail /Users/jianshuzhao/Github/parasail-sys/parasail/build /Users/jianshuzhao/Github/parasail-sys/parasail/build /Users/jianshuzhao/Github/parasail-sys/parasail/build/CMakeFiles/ssw.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ssw.dir/depend

