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
CMAKE_SOURCE_DIR = /home/cippzz/autoirriga

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cippzz/autoirriga/build/Desktop-Debug

# Include any dependencies generated for this target.
include CMakeFiles/autoirriga.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/autoirriga.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/autoirriga.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/autoirriga.dir/flags.make

autoirriga_autogen/timestamp: /usr/lib/qt5/bin/moc
autoirriga_autogen/timestamp: /usr/lib/qt5/bin/uic
autoirriga_autogen/timestamp: CMakeFiles/autoirriga.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/cippzz/autoirriga/build/Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target autoirriga"
	/usr/bin/cmake -E cmake_autogen /home/cippzz/autoirriga/build/Desktop-Debug/CMakeFiles/autoirriga_autogen.dir/AutogenInfo.json Debug
	/usr/bin/cmake -E touch /home/cippzz/autoirriga/build/Desktop-Debug/autoirriga_autogen/timestamp

CMakeFiles/autoirriga.dir/autoirriga_autogen/mocs_compilation.cpp.o: CMakeFiles/autoirriga.dir/flags.make
CMakeFiles/autoirriga.dir/autoirriga_autogen/mocs_compilation.cpp.o: autoirriga_autogen/mocs_compilation.cpp
CMakeFiles/autoirriga.dir/autoirriga_autogen/mocs_compilation.cpp.o: CMakeFiles/autoirriga.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/cippzz/autoirriga/build/Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/autoirriga.dir/autoirriga_autogen/mocs_compilation.cpp.o"
	/usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/autoirriga.dir/autoirriga_autogen/mocs_compilation.cpp.o -MF CMakeFiles/autoirriga.dir/autoirriga_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/autoirriga.dir/autoirriga_autogen/mocs_compilation.cpp.o -c /home/cippzz/autoirriga/build/Desktop-Debug/autoirriga_autogen/mocs_compilation.cpp

CMakeFiles/autoirriga.dir/autoirriga_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/autoirriga.dir/autoirriga_autogen/mocs_compilation.cpp.i"
	/usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cippzz/autoirriga/build/Desktop-Debug/autoirriga_autogen/mocs_compilation.cpp > CMakeFiles/autoirriga.dir/autoirriga_autogen/mocs_compilation.cpp.i

CMakeFiles/autoirriga.dir/autoirriga_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/autoirriga.dir/autoirriga_autogen/mocs_compilation.cpp.s"
	/usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cippzz/autoirriga/build/Desktop-Debug/autoirriga_autogen/mocs_compilation.cpp -o CMakeFiles/autoirriga.dir/autoirriga_autogen/mocs_compilation.cpp.s

CMakeFiles/autoirriga.dir/main.cpp.o: CMakeFiles/autoirriga.dir/flags.make
CMakeFiles/autoirriga.dir/main.cpp.o: /home/cippzz/autoirriga/main.cpp
CMakeFiles/autoirriga.dir/main.cpp.o: CMakeFiles/autoirriga.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/cippzz/autoirriga/build/Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/autoirriga.dir/main.cpp.o"
	/usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/autoirriga.dir/main.cpp.o -MF CMakeFiles/autoirriga.dir/main.cpp.o.d -o CMakeFiles/autoirriga.dir/main.cpp.o -c /home/cippzz/autoirriga/main.cpp

CMakeFiles/autoirriga.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/autoirriga.dir/main.cpp.i"
	/usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cippzz/autoirriga/main.cpp > CMakeFiles/autoirriga.dir/main.cpp.i

CMakeFiles/autoirriga.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/autoirriga.dir/main.cpp.s"
	/usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cippzz/autoirriga/main.cpp -o CMakeFiles/autoirriga.dir/main.cpp.s

CMakeFiles/autoirriga.dir/mainwindow.cpp.o: CMakeFiles/autoirriga.dir/flags.make
CMakeFiles/autoirriga.dir/mainwindow.cpp.o: /home/cippzz/autoirriga/mainwindow.cpp
CMakeFiles/autoirriga.dir/mainwindow.cpp.o: CMakeFiles/autoirriga.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/cippzz/autoirriga/build/Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/autoirriga.dir/mainwindow.cpp.o"
	/usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/autoirriga.dir/mainwindow.cpp.o -MF CMakeFiles/autoirriga.dir/mainwindow.cpp.o.d -o CMakeFiles/autoirriga.dir/mainwindow.cpp.o -c /home/cippzz/autoirriga/mainwindow.cpp

CMakeFiles/autoirriga.dir/mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/autoirriga.dir/mainwindow.cpp.i"
	/usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cippzz/autoirriga/mainwindow.cpp > CMakeFiles/autoirriga.dir/mainwindow.cpp.i

CMakeFiles/autoirriga.dir/mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/autoirriga.dir/mainwindow.cpp.s"
	/usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cippzz/autoirriga/mainwindow.cpp -o CMakeFiles/autoirriga.dir/mainwindow.cpp.s

# Object files for target autoirriga
autoirriga_OBJECTS = \
"CMakeFiles/autoirriga.dir/autoirriga_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/autoirriga.dir/main.cpp.o" \
"CMakeFiles/autoirriga.dir/mainwindow.cpp.o"

# External object files for target autoirriga
autoirriga_EXTERNAL_OBJECTS =

autoirriga: CMakeFiles/autoirriga.dir/autoirriga_autogen/mocs_compilation.cpp.o
autoirriga: CMakeFiles/autoirriga.dir/main.cpp.o
autoirriga: CMakeFiles/autoirriga.dir/mainwindow.cpp.o
autoirriga: CMakeFiles/autoirriga.dir/build.make
autoirriga: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.15.13
autoirriga: /usr/lib/x86_64-linux-gnu/libQt5SerialPort.so.5.15.13
autoirriga: /usr/lib/x86_64-linux-gnu/libQt5Network.so.5.15.13
autoirriga: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.13
autoirriga: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.13
autoirriga: CMakeFiles/autoirriga.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/cippzz/autoirriga/build/Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable autoirriga"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/autoirriga.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/autoirriga.dir/build: autoirriga
.PHONY : CMakeFiles/autoirriga.dir/build

CMakeFiles/autoirriga.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/autoirriga.dir/cmake_clean.cmake
.PHONY : CMakeFiles/autoirriga.dir/clean

CMakeFiles/autoirriga.dir/depend: autoirriga_autogen/timestamp
	cd /home/cippzz/autoirriga/build/Desktop-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cippzz/autoirriga /home/cippzz/autoirriga /home/cippzz/autoirriga/build/Desktop-Debug /home/cippzz/autoirriga/build/Desktop-Debug /home/cippzz/autoirriga/build/Desktop-Debug/CMakeFiles/autoirriga.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/autoirriga.dir/depend

