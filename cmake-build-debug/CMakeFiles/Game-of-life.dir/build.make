# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/wojkly/clion-2020.3.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/wojkly/clion-2020.3.3/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/wojkly/Documents/STUDIA/cpp/Game-of-life

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wojkly/Documents/STUDIA/cpp/Game-of-life/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Game-of-life.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Game-of-life.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Game-of-life.dir/flags.make

CMakeFiles/Game-of-life.dir/main.cpp.o: CMakeFiles/Game-of-life.dir/flags.make
CMakeFiles/Game-of-life.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wojkly/Documents/STUDIA/cpp/Game-of-life/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Game-of-life.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Game-of-life.dir/main.cpp.o -c /home/wojkly/Documents/STUDIA/cpp/Game-of-life/main.cpp

CMakeFiles/Game-of-life.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Game-of-life.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wojkly/Documents/STUDIA/cpp/Game-of-life/main.cpp > CMakeFiles/Game-of-life.dir/main.cpp.i

CMakeFiles/Game-of-life.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Game-of-life.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wojkly/Documents/STUDIA/cpp/Game-of-life/main.cpp -o CMakeFiles/Game-of-life.dir/main.cpp.s

CMakeFiles/Game-of-life.dir/Application.cpp.o: CMakeFiles/Game-of-life.dir/flags.make
CMakeFiles/Game-of-life.dir/Application.cpp.o: ../Application.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wojkly/Documents/STUDIA/cpp/Game-of-life/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Game-of-life.dir/Application.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Game-of-life.dir/Application.cpp.o -c /home/wojkly/Documents/STUDIA/cpp/Game-of-life/Application.cpp

CMakeFiles/Game-of-life.dir/Application.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Game-of-life.dir/Application.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wojkly/Documents/STUDIA/cpp/Game-of-life/Application.cpp > CMakeFiles/Game-of-life.dir/Application.cpp.i

CMakeFiles/Game-of-life.dir/Application.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Game-of-life.dir/Application.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wojkly/Documents/STUDIA/cpp/Game-of-life/Application.cpp -o CMakeFiles/Game-of-life.dir/Application.cpp.s

CMakeFiles/Game-of-life.dir/DoublePendulum.cpp.o: CMakeFiles/Game-of-life.dir/flags.make
CMakeFiles/Game-of-life.dir/DoublePendulum.cpp.o: ../DoublePendulum.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wojkly/Documents/STUDIA/cpp/Game-of-life/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Game-of-life.dir/DoublePendulum.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Game-of-life.dir/DoublePendulum.cpp.o -c /home/wojkly/Documents/STUDIA/cpp/Game-of-life/DoublePendulum.cpp

CMakeFiles/Game-of-life.dir/DoublePendulum.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Game-of-life.dir/DoublePendulum.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wojkly/Documents/STUDIA/cpp/Game-of-life/DoublePendulum.cpp > CMakeFiles/Game-of-life.dir/DoublePendulum.cpp.i

CMakeFiles/Game-of-life.dir/DoublePendulum.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Game-of-life.dir/DoublePendulum.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wojkly/Documents/STUDIA/cpp/Game-of-life/DoublePendulum.cpp -o CMakeFiles/Game-of-life.dir/DoublePendulum.cpp.s

CMakeFiles/Game-of-life.dir/PendulumEquation.cpp.o: CMakeFiles/Game-of-life.dir/flags.make
CMakeFiles/Game-of-life.dir/PendulumEquation.cpp.o: ../PendulumEquation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wojkly/Documents/STUDIA/cpp/Game-of-life/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Game-of-life.dir/PendulumEquation.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Game-of-life.dir/PendulumEquation.cpp.o -c /home/wojkly/Documents/STUDIA/cpp/Game-of-life/PendulumEquation.cpp

CMakeFiles/Game-of-life.dir/PendulumEquation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Game-of-life.dir/PendulumEquation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wojkly/Documents/STUDIA/cpp/Game-of-life/PendulumEquation.cpp > CMakeFiles/Game-of-life.dir/PendulumEquation.cpp.i

CMakeFiles/Game-of-life.dir/PendulumEquation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Game-of-life.dir/PendulumEquation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wojkly/Documents/STUDIA/cpp/Game-of-life/PendulumEquation.cpp -o CMakeFiles/Game-of-life.dir/PendulumEquation.cpp.s

# Object files for target Game-of-life
Game__of__life_OBJECTS = \
"CMakeFiles/Game-of-life.dir/main.cpp.o" \
"CMakeFiles/Game-of-life.dir/Application.cpp.o" \
"CMakeFiles/Game-of-life.dir/DoublePendulum.cpp.o" \
"CMakeFiles/Game-of-life.dir/PendulumEquation.cpp.o"

# External object files for target Game-of-life
Game__of__life_EXTERNAL_OBJECTS =

../Game-of-life: CMakeFiles/Game-of-life.dir/main.cpp.o
../Game-of-life: CMakeFiles/Game-of-life.dir/Application.cpp.o
../Game-of-life: CMakeFiles/Game-of-life.dir/DoublePendulum.cpp.o
../Game-of-life: CMakeFiles/Game-of-life.dir/PendulumEquation.cpp.o
../Game-of-life: CMakeFiles/Game-of-life.dir/build.make
../Game-of-life: ../SFML/lib/libsfml-graphics.so.2.5.1
../Game-of-life: ../SFML/lib/libsfml-audio.so.2.5.1
../Game-of-life: ../SFML/lib/libsfml-window.so.2.5.1
../Game-of-life: ../SFML/lib/libsfml-system.so.2.5.1
../Game-of-life: CMakeFiles/Game-of-life.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wojkly/Documents/STUDIA/cpp/Game-of-life/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable ../Game-of-life"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Game-of-life.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Game-of-life.dir/build: ../Game-of-life

.PHONY : CMakeFiles/Game-of-life.dir/build

CMakeFiles/Game-of-life.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Game-of-life.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Game-of-life.dir/clean

CMakeFiles/Game-of-life.dir/depend:
	cd /home/wojkly/Documents/STUDIA/cpp/Game-of-life/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wojkly/Documents/STUDIA/cpp/Game-of-life /home/wojkly/Documents/STUDIA/cpp/Game-of-life /home/wojkly/Documents/STUDIA/cpp/Game-of-life/cmake-build-debug /home/wojkly/Documents/STUDIA/cpp/Game-of-life/cmake-build-debug /home/wojkly/Documents/STUDIA/cpp/Game-of-life/cmake-build-debug/CMakeFiles/Game-of-life.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Game-of-life.dir/depend

