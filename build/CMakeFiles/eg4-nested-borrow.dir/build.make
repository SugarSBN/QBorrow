# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 4.0

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
CMAKE_COMMAND = /opt/homebrew/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/subonan/subonan_THU/QBorrow

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/subonan/subonan_THU/QBorrow/build

# Utility rule file for eg4-nested-borrow.

# Include any custom commands dependencies for this target.
include CMakeFiles/eg4-nested-borrow.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/eg4-nested-borrow.dir/progress.make

CMakeFiles/eg4-nested-borrow: qborrow
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/subonan/subonan_THU/QBorrow/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Running qborrow with example eg4-nested-borrow.qbr"
	env DYLD_LIBRARY_PATH="/opt/homebrew/lib" /Users/subonan/subonan_THU/QBorrow/build/qborrow /Users/subonan/subonan_THU/QBorrow/examples/eg4-nested-borrow.qbr $(ARGS)

CMakeFiles/eg4-nested-borrow.dir/codegen:
.PHONY : CMakeFiles/eg4-nested-borrow.dir/codegen

eg4-nested-borrow: CMakeFiles/eg4-nested-borrow
eg4-nested-borrow: CMakeFiles/eg4-nested-borrow.dir/build.make
.PHONY : eg4-nested-borrow

# Rule to build all files generated by this target.
CMakeFiles/eg4-nested-borrow.dir/build: eg4-nested-borrow
.PHONY : CMakeFiles/eg4-nested-borrow.dir/build

CMakeFiles/eg4-nested-borrow.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/eg4-nested-borrow.dir/cmake_clean.cmake
.PHONY : CMakeFiles/eg4-nested-borrow.dir/clean

CMakeFiles/eg4-nested-borrow.dir/depend:
	cd /Users/subonan/subonan_THU/QBorrow/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/subonan/subonan_THU/QBorrow /Users/subonan/subonan_THU/QBorrow /Users/subonan/subonan_THU/QBorrow/build /Users/subonan/subonan_THU/QBorrow/build /Users/subonan/subonan_THU/QBorrow/build/CMakeFiles/eg4-nested-borrow.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/eg4-nested-borrow.dir/depend

