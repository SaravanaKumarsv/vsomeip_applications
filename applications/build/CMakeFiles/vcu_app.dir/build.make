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
CMAKE_SOURCE_DIR = /home/saravana/someip_application/applications

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/saravana/someip_application/applications/build

# Include any dependencies generated for this target.
include CMakeFiles/vcu_app.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/vcu_app.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/vcu_app.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/vcu_app.dir/flags.make

CMakeFiles/vcu_app.dir/src/vcu_app.cpp.o: CMakeFiles/vcu_app.dir/flags.make
CMakeFiles/vcu_app.dir/src/vcu_app.cpp.o: /home/saravana/someip_application/applications/src/vcu_app.cpp
CMakeFiles/vcu_app.dir/src/vcu_app.cpp.o: CMakeFiles/vcu_app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/saravana/someip_application/applications/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/vcu_app.dir/src/vcu_app.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/vcu_app.dir/src/vcu_app.cpp.o -MF CMakeFiles/vcu_app.dir/src/vcu_app.cpp.o.d -o CMakeFiles/vcu_app.dir/src/vcu_app.cpp.o -c /home/saravana/someip_application/applications/src/vcu_app.cpp

CMakeFiles/vcu_app.dir/src/vcu_app.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/vcu_app.dir/src/vcu_app.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/saravana/someip_application/applications/src/vcu_app.cpp > CMakeFiles/vcu_app.dir/src/vcu_app.cpp.i

CMakeFiles/vcu_app.dir/src/vcu_app.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/vcu_app.dir/src/vcu_app.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/saravana/someip_application/applications/src/vcu_app.cpp -o CMakeFiles/vcu_app.dir/src/vcu_app.cpp.s

# Object files for target vcu_app
vcu_app_OBJECTS = \
"CMakeFiles/vcu_app.dir/src/vcu_app.cpp.o"

# External object files for target vcu_app
vcu_app_EXTERNAL_OBJECTS =

vcu_app: CMakeFiles/vcu_app.dir/src/vcu_app.cpp.o
vcu_app: CMakeFiles/vcu_app.dir/build.make
vcu_app: /usr/local/lib/libvsomeip3.so.3.5.5
vcu_app: /usr/lib/x86_64-linux-gnu/libboost_system.so.1.83.0
vcu_app: /usr/lib/x86_64-linux-gnu/libboost_log.so.1.83.0
vcu_app: /usr/lib/x86_64-linux-gnu/libboost_thread.so.1.83.0
vcu_app: /usr/lib/x86_64-linux-gnu/libboost_chrono.so.1.83.0
vcu_app: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so.1.83.0
vcu_app: /usr/lib/x86_64-linux-gnu/libboost_atomic.so.1.83.0
vcu_app: /usr/lib/x86_64-linux-gnu/libboost_regex.so.1.83.0
vcu_app: CMakeFiles/vcu_app.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/saravana/someip_application/applications/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable vcu_app"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/vcu_app.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/vcu_app.dir/build: vcu_app
.PHONY : CMakeFiles/vcu_app.dir/build

CMakeFiles/vcu_app.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/vcu_app.dir/cmake_clean.cmake
.PHONY : CMakeFiles/vcu_app.dir/clean

CMakeFiles/vcu_app.dir/depend:
	cd /home/saravana/someip_application/applications/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/saravana/someip_application/applications /home/saravana/someip_application/applications /home/saravana/someip_application/applications/build /home/saravana/someip_application/applications/build /home/saravana/someip_application/applications/build/CMakeFiles/vcu_app.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/vcu_app.dir/depend

