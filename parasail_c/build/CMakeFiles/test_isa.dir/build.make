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
include CMakeFiles/test_isa.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/test_isa.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test_isa.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_isa.dir/flags.make

CMakeFiles/test_isa.dir/tests/test_isa.c.o: CMakeFiles/test_isa.dir/flags.make
CMakeFiles/test_isa.dir/tests/test_isa.c.o: ../tests/test_isa.c
CMakeFiles/test_isa.dir/tests/test_isa.c.o: CMakeFiles/test_isa.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jianshuzhao/Github/parasail-sys/parasail/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/test_isa.dir/tests/test_isa.c.o"
	/usr/local/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/test_isa.dir/tests/test_isa.c.o -MF CMakeFiles/test_isa.dir/tests/test_isa.c.o.d -o CMakeFiles/test_isa.dir/tests/test_isa.c.o -c /Users/jianshuzhao/Github/parasail-sys/parasail/tests/test_isa.c

CMakeFiles/test_isa.dir/tests/test_isa.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_isa.dir/tests/test_isa.c.i"
	/usr/local/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jianshuzhao/Github/parasail-sys/parasail/tests/test_isa.c > CMakeFiles/test_isa.dir/tests/test_isa.c.i

CMakeFiles/test_isa.dir/tests/test_isa.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_isa.dir/tests/test_isa.c.s"
	/usr/local/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jianshuzhao/Github/parasail-sys/parasail/tests/test_isa.c -o CMakeFiles/test_isa.dir/tests/test_isa.c.s

# Object files for target test_isa
test_isa_OBJECTS = \
"CMakeFiles/test_isa.dir/tests/test_isa.c.o"

# External object files for target test_isa
test_isa_EXTERNAL_OBJECTS =

test_isa: CMakeFiles/test_isa.dir/tests/test_isa.c.o
test_isa: CMakeFiles/test_isa.dir/build.make
test_isa: libparasail.dylib
test_isa: /Library/Developer/CommandLineTools/SDKs/MacOSX12.3.sdk/usr/lib/libz.tbd
test_isa: CMakeFiles/test_isa.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jianshuzhao/Github/parasail-sys/parasail/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable test_isa"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_isa.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_isa.dir/build: test_isa
.PHONY : CMakeFiles/test_isa.dir/build

CMakeFiles/test_isa.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_isa.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_isa.dir/clean

CMakeFiles/test_isa.dir/depend:
	cd /Users/jianshuzhao/Github/parasail-sys/parasail/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jianshuzhao/Github/parasail-sys/parasail /Users/jianshuzhao/Github/parasail-sys/parasail /Users/jianshuzhao/Github/parasail-sys/parasail/build /Users/jianshuzhao/Github/parasail-sys/parasail/build /Users/jianshuzhao/Github/parasail-sys/parasail/build/CMakeFiles/test_isa.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_isa.dir/depend

