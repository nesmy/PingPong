# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/Nesmy/Playground/PingPong

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/Nesmy/Playground/PingPong/build

# Include any dependencies generated for this target.
include CMakeFiles/PingPong.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/PingPong.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/PingPong.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PingPong.dir/flags.make

CMakeFiles/PingPong.dir/src/Game.cpp.o: CMakeFiles/PingPong.dir/flags.make
CMakeFiles/PingPong.dir/src/Game.cpp.o: /home/Nesmy/Playground/PingPong/src/Game.cpp
CMakeFiles/PingPong.dir/src/Game.cpp.o: CMakeFiles/PingPong.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/Nesmy/Playground/PingPong/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PingPong.dir/src/Game.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/PingPong.dir/src/Game.cpp.o -MF CMakeFiles/PingPong.dir/src/Game.cpp.o.d -o CMakeFiles/PingPong.dir/src/Game.cpp.o -c /home/Nesmy/Playground/PingPong/src/Game.cpp

CMakeFiles/PingPong.dir/src/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/PingPong.dir/src/Game.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/Nesmy/Playground/PingPong/src/Game.cpp > CMakeFiles/PingPong.dir/src/Game.cpp.i

CMakeFiles/PingPong.dir/src/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/PingPong.dir/src/Game.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/Nesmy/Playground/PingPong/src/Game.cpp -o CMakeFiles/PingPong.dir/src/Game.cpp.s

# Object files for target PingPong
PingPong_OBJECTS = \
"CMakeFiles/PingPong.dir/src/Game.cpp.o"

# External object files for target PingPong
PingPong_EXTERNAL_OBJECTS =

PingPong: CMakeFiles/PingPong.dir/src/Game.cpp.o
PingPong: CMakeFiles/PingPong.dir/build.make
PingPong: vendor/raylib/raylib/libraylib.a
PingPong: /usr/lib/libOpenGL.so
PingPong: /usr/lib/libGLX.so
PingPong: /usr/lib/libGLU.so
PingPong: vendor/raylib/raylib/external/glfw/src/libglfw3.a
PingPong: /usr/lib/librt.a
PingPong: /usr/lib/libm.so
PingPong: CMakeFiles/PingPong.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/Nesmy/Playground/PingPong/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable PingPong"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PingPong.dir/link.txt --verbose=$(VERBOSE)
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold "Copying to output directory"
	/usr/bin/cmake -E copy_directory /home/Nesmy/Playground/PingPong/assets /home/Nesmy/Playground/PingPong/build/assets

# Rule to build all files generated by this target.
CMakeFiles/PingPong.dir/build: PingPong
.PHONY : CMakeFiles/PingPong.dir/build

CMakeFiles/PingPong.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PingPong.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PingPong.dir/clean

CMakeFiles/PingPong.dir/depend:
	cd /home/Nesmy/Playground/PingPong/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/Nesmy/Playground/PingPong /home/Nesmy/Playground/PingPong /home/Nesmy/Playground/PingPong/build /home/Nesmy/Playground/PingPong/build /home/Nesmy/Playground/PingPong/build/CMakeFiles/PingPong.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/PingPong.dir/depend

