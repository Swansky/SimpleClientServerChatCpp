# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = "/Users/swansky/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/212.5457.51/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/swansky/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/212.5457.51/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/swansky/Desktop/Projects/client-serverChat/clientChat

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/swansky/Desktop/Projects/client-serverChat/clientChat/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/clientChat.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/clientChat.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/clientChat.dir/flags.make

CMakeFiles/clientChat.dir/main.cpp.o: CMakeFiles/clientChat.dir/flags.make
CMakeFiles/clientChat.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/swansky/Desktop/Projects/client-serverChat/clientChat/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/clientChat.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/clientChat.dir/main.cpp.o -c /Users/swansky/Desktop/Projects/client-serverChat/clientChat/main.cpp

CMakeFiles/clientChat.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/clientChat.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/swansky/Desktop/Projects/client-serverChat/clientChat/main.cpp > CMakeFiles/clientChat.dir/main.cpp.i

CMakeFiles/clientChat.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/clientChat.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/swansky/Desktop/Projects/client-serverChat/clientChat/main.cpp -o CMakeFiles/clientChat.dir/main.cpp.s

# Object files for target clientChat
clientChat_OBJECTS = \
"CMakeFiles/clientChat.dir/main.cpp.o"

# External object files for target clientChat
clientChat_EXTERNAL_OBJECTS =

clientChat: CMakeFiles/clientChat.dir/main.cpp.o
clientChat: CMakeFiles/clientChat.dir/build.make
clientChat: CMakeFiles/clientChat.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/swansky/Desktop/Projects/client-serverChat/clientChat/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable clientChat"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/clientChat.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/clientChat.dir/build: clientChat
.PHONY : CMakeFiles/clientChat.dir/build

CMakeFiles/clientChat.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/clientChat.dir/cmake_clean.cmake
.PHONY : CMakeFiles/clientChat.dir/clean

CMakeFiles/clientChat.dir/depend:
	cd /Users/swansky/Desktop/Projects/client-serverChat/clientChat/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/swansky/Desktop/Projects/client-serverChat/clientChat /Users/swansky/Desktop/Projects/client-serverChat/clientChat /Users/swansky/Desktop/Projects/client-serverChat/clientChat/cmake-build-debug /Users/swansky/Desktop/Projects/client-serverChat/clientChat/cmake-build-debug /Users/swansky/Desktop/Projects/client-serverChat/clientChat/cmake-build-debug/CMakeFiles/clientChat.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/clientChat.dir/depend

