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
CMAKE_COMMAND = /snap/clion/138/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/138/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/raluca/Documents/RC/OfflineMessenger

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/raluca/Documents/RC/OfflineMessenger/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/OfflineMessenger.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/OfflineMessenger.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OfflineMessenger.dir/flags.make

CMakeFiles/OfflineMessenger.dir/svMessenger.cpp.o: CMakeFiles/OfflineMessenger.dir/flags.make
CMakeFiles/OfflineMessenger.dir/svMessenger.cpp.o: ../svMessenger.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/raluca/Documents/RC/OfflineMessenger/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OfflineMessenger.dir/svMessenger.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OfflineMessenger.dir/svMessenger.cpp.o -c /home/raluca/Documents/RC/OfflineMessenger/svMessenger.cpp

CMakeFiles/OfflineMessenger.dir/svMessenger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OfflineMessenger.dir/svMessenger.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/raluca/Documents/RC/OfflineMessenger/svMessenger.cpp > CMakeFiles/OfflineMessenger.dir/svMessenger.cpp.i

CMakeFiles/OfflineMessenger.dir/svMessenger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OfflineMessenger.dir/svMessenger.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/raluca/Documents/RC/OfflineMessenger/svMessenger.cpp -o CMakeFiles/OfflineMessenger.dir/svMessenger.cpp.s

CMakeFiles/OfflineMessenger.dir/server.cpp.o: CMakeFiles/OfflineMessenger.dir/flags.make
CMakeFiles/OfflineMessenger.dir/server.cpp.o: ../server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/raluca/Documents/RC/OfflineMessenger/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/OfflineMessenger.dir/server.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OfflineMessenger.dir/server.cpp.o -c /home/raluca/Documents/RC/OfflineMessenger/server.cpp

CMakeFiles/OfflineMessenger.dir/server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OfflineMessenger.dir/server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/raluca/Documents/RC/OfflineMessenger/server.cpp > CMakeFiles/OfflineMessenger.dir/server.cpp.i

CMakeFiles/OfflineMessenger.dir/server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OfflineMessenger.dir/server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/raluca/Documents/RC/OfflineMessenger/server.cpp -o CMakeFiles/OfflineMessenger.dir/server.cpp.s

CMakeFiles/OfflineMessenger.dir/client.cpp.o: CMakeFiles/OfflineMessenger.dir/flags.make
CMakeFiles/OfflineMessenger.dir/client.cpp.o: ../client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/raluca/Documents/RC/OfflineMessenger/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/OfflineMessenger.dir/client.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OfflineMessenger.dir/client.cpp.o -c /home/raluca/Documents/RC/OfflineMessenger/client.cpp

CMakeFiles/OfflineMessenger.dir/client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OfflineMessenger.dir/client.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/raluca/Documents/RC/OfflineMessenger/client.cpp > CMakeFiles/OfflineMessenger.dir/client.cpp.i

CMakeFiles/OfflineMessenger.dir/client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OfflineMessenger.dir/client.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/raluca/Documents/RC/OfflineMessenger/client.cpp -o CMakeFiles/OfflineMessenger.dir/client.cpp.s

CMakeFiles/OfflineMessenger.dir/clMessenger.cpp.o: CMakeFiles/OfflineMessenger.dir/flags.make
CMakeFiles/OfflineMessenger.dir/clMessenger.cpp.o: ../clMessenger.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/raluca/Documents/RC/OfflineMessenger/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/OfflineMessenger.dir/clMessenger.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OfflineMessenger.dir/clMessenger.cpp.o -c /home/raluca/Documents/RC/OfflineMessenger/clMessenger.cpp

CMakeFiles/OfflineMessenger.dir/clMessenger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OfflineMessenger.dir/clMessenger.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/raluca/Documents/RC/OfflineMessenger/clMessenger.cpp > CMakeFiles/OfflineMessenger.dir/clMessenger.cpp.i

CMakeFiles/OfflineMessenger.dir/clMessenger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OfflineMessenger.dir/clMessenger.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/raluca/Documents/RC/OfflineMessenger/clMessenger.cpp -o CMakeFiles/OfflineMessenger.dir/clMessenger.cpp.s

# Object files for target OfflineMessenger
OfflineMessenger_OBJECTS = \
"CMakeFiles/OfflineMessenger.dir/svMessenger.cpp.o" \
"CMakeFiles/OfflineMessenger.dir/server.cpp.o" \
"CMakeFiles/OfflineMessenger.dir/client.cpp.o" \
"CMakeFiles/OfflineMessenger.dir/clMessenger.cpp.o"

# External object files for target OfflineMessenger
OfflineMessenger_EXTERNAL_OBJECTS =

OfflineMessenger: CMakeFiles/OfflineMessenger.dir/svMessenger.cpp.o
OfflineMessenger: CMakeFiles/OfflineMessenger.dir/server.cpp.o
OfflineMessenger: CMakeFiles/OfflineMessenger.dir/client.cpp.o
OfflineMessenger: CMakeFiles/OfflineMessenger.dir/clMessenger.cpp.o
OfflineMessenger: CMakeFiles/OfflineMessenger.dir/build.make
OfflineMessenger: CMakeFiles/OfflineMessenger.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/raluca/Documents/RC/OfflineMessenger/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable OfflineMessenger"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/OfflineMessenger.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OfflineMessenger.dir/build: OfflineMessenger

.PHONY : CMakeFiles/OfflineMessenger.dir/build

CMakeFiles/OfflineMessenger.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/OfflineMessenger.dir/cmake_clean.cmake
.PHONY : CMakeFiles/OfflineMessenger.dir/clean

CMakeFiles/OfflineMessenger.dir/depend:
	cd /home/raluca/Documents/RC/OfflineMessenger/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/raluca/Documents/RC/OfflineMessenger /home/raluca/Documents/RC/OfflineMessenger /home/raluca/Documents/RC/OfflineMessenger/cmake-build-debug /home/raluca/Documents/RC/OfflineMessenger/cmake-build-debug /home/raluca/Documents/RC/OfflineMessenger/cmake-build-debug/CMakeFiles/OfflineMessenger.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/OfflineMessenger.dir/depend

