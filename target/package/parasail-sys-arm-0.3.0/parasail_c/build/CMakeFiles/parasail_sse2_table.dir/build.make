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
include CMakeFiles/parasail_sse2_table.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/parasail_sse2_table.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/parasail_sse2_table.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/parasail_sse2_table.dir/flags.make

CMakeFiles/parasail_sse2_table.dir/cmake/sse2_dummy.c.o: CMakeFiles/parasail_sse2_table.dir/flags.make
CMakeFiles/parasail_sse2_table.dir/cmake/sse2_dummy.c.o: ../cmake/sse2_dummy.c
CMakeFiles/parasail_sse2_table.dir/cmake/sse2_dummy.c.o: CMakeFiles/parasail_sse2_table.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jianshuzhao/Github/parasail-sys/parasail/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/parasail_sse2_table.dir/cmake/sse2_dummy.c.o"
	/usr/local/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/parasail_sse2_table.dir/cmake/sse2_dummy.c.o -MF CMakeFiles/parasail_sse2_table.dir/cmake/sse2_dummy.c.o.d -o CMakeFiles/parasail_sse2_table.dir/cmake/sse2_dummy.c.o -c /Users/jianshuzhao/Github/parasail-sys/parasail/cmake/sse2_dummy.c

CMakeFiles/parasail_sse2_table.dir/cmake/sse2_dummy.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/parasail_sse2_table.dir/cmake/sse2_dummy.c.i"
	/usr/local/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jianshuzhao/Github/parasail-sys/parasail/cmake/sse2_dummy.c > CMakeFiles/parasail_sse2_table.dir/cmake/sse2_dummy.c.i

CMakeFiles/parasail_sse2_table.dir/cmake/sse2_dummy.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/parasail_sse2_table.dir/cmake/sse2_dummy.c.s"
	/usr/local/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jianshuzhao/Github/parasail-sys/parasail/cmake/sse2_dummy.c -o CMakeFiles/parasail_sse2_table.dir/cmake/sse2_dummy.c.s

parasail_sse2_table: CMakeFiles/parasail_sse2_table.dir/cmake/sse2_dummy.c.o
parasail_sse2_table: CMakeFiles/parasail_sse2_table.dir/build.make
.PHONY : parasail_sse2_table

# Rule to build all files generated by this target.
CMakeFiles/parasail_sse2_table.dir/build: parasail_sse2_table
.PHONY : CMakeFiles/parasail_sse2_table.dir/build

CMakeFiles/parasail_sse2_table.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/parasail_sse2_table.dir/cmake_clean.cmake
.PHONY : CMakeFiles/parasail_sse2_table.dir/clean

CMakeFiles/parasail_sse2_table.dir/depend:
	cd /Users/jianshuzhao/Github/parasail-sys/parasail/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jianshuzhao/Github/parasail-sys/parasail /Users/jianshuzhao/Github/parasail-sys/parasail /Users/jianshuzhao/Github/parasail-sys/parasail/build /Users/jianshuzhao/Github/parasail-sys/parasail/build /Users/jianshuzhao/Github/parasail-sys/parasail/build/CMakeFiles/parasail_sse2_table.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/parasail_sse2_table.dir/depend

