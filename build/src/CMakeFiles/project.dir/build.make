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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kostya/ProjectForC++/SLAU

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kostya/ProjectForC++/SLAU/build

# Include any dependencies generated for this target.
include src/CMakeFiles/project.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/project.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/project.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/project.dir/flags.make

src/CMakeFiles/project.dir/project/containers/vector.cpp.o: src/CMakeFiles/project.dir/flags.make
src/CMakeFiles/project.dir/project/containers/vector.cpp.o: ../src/project/containers/vector.cpp
src/CMakeFiles/project.dir/project/containers/vector.cpp.o: src/CMakeFiles/project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kostya/ProjectForC++/SLAU/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/project.dir/project/containers/vector.cpp.o"
	cd /home/kostya/ProjectForC++/SLAU/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/project.dir/project/containers/vector.cpp.o -MF CMakeFiles/project.dir/project/containers/vector.cpp.o.d -o CMakeFiles/project.dir/project/containers/vector.cpp.o -c /home/kostya/ProjectForC++/SLAU/src/project/containers/vector.cpp

src/CMakeFiles/project.dir/project/containers/vector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project.dir/project/containers/vector.cpp.i"
	cd /home/kostya/ProjectForC++/SLAU/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kostya/ProjectForC++/SLAU/src/project/containers/vector.cpp > CMakeFiles/project.dir/project/containers/vector.cpp.i

src/CMakeFiles/project.dir/project/containers/vector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project.dir/project/containers/vector.cpp.s"
	cd /home/kostya/ProjectForC++/SLAU/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kostya/ProjectForC++/SLAU/src/project/containers/vector.cpp -o CMakeFiles/project.dir/project/containers/vector.cpp.s

src/CMakeFiles/project.dir/project/matrix/CSR/CSR.cpp.o: src/CMakeFiles/project.dir/flags.make
src/CMakeFiles/project.dir/project/matrix/CSR/CSR.cpp.o: ../src/project/matrix/CSR/CSR.cpp
src/CMakeFiles/project.dir/project/matrix/CSR/CSR.cpp.o: src/CMakeFiles/project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kostya/ProjectForC++/SLAU/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/project.dir/project/matrix/CSR/CSR.cpp.o"
	cd /home/kostya/ProjectForC++/SLAU/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/project.dir/project/matrix/CSR/CSR.cpp.o -MF CMakeFiles/project.dir/project/matrix/CSR/CSR.cpp.o.d -o CMakeFiles/project.dir/project/matrix/CSR/CSR.cpp.o -c /home/kostya/ProjectForC++/SLAU/src/project/matrix/CSR/CSR.cpp

src/CMakeFiles/project.dir/project/matrix/CSR/CSR.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project.dir/project/matrix/CSR/CSR.cpp.i"
	cd /home/kostya/ProjectForC++/SLAU/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kostya/ProjectForC++/SLAU/src/project/matrix/CSR/CSR.cpp > CMakeFiles/project.dir/project/matrix/CSR/CSR.cpp.i

src/CMakeFiles/project.dir/project/matrix/CSR/CSR.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project.dir/project/matrix/CSR/CSR.cpp.s"
	cd /home/kostya/ProjectForC++/SLAU/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kostya/ProjectForC++/SLAU/src/project/matrix/CSR/CSR.cpp -o CMakeFiles/project.dir/project/matrix/CSR/CSR.cpp.s

src/CMakeFiles/project.dir/project/matrix/ThreeDiag/ThreeDiag.cpp.o: src/CMakeFiles/project.dir/flags.make
src/CMakeFiles/project.dir/project/matrix/ThreeDiag/ThreeDiag.cpp.o: ../src/project/matrix/ThreeDiag/ThreeDiag.cpp
src/CMakeFiles/project.dir/project/matrix/ThreeDiag/ThreeDiag.cpp.o: src/CMakeFiles/project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kostya/ProjectForC++/SLAU/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/project.dir/project/matrix/ThreeDiag/ThreeDiag.cpp.o"
	cd /home/kostya/ProjectForC++/SLAU/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/project.dir/project/matrix/ThreeDiag/ThreeDiag.cpp.o -MF CMakeFiles/project.dir/project/matrix/ThreeDiag/ThreeDiag.cpp.o.d -o CMakeFiles/project.dir/project/matrix/ThreeDiag/ThreeDiag.cpp.o -c /home/kostya/ProjectForC++/SLAU/src/project/matrix/ThreeDiag/ThreeDiag.cpp

src/CMakeFiles/project.dir/project/matrix/ThreeDiag/ThreeDiag.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project.dir/project/matrix/ThreeDiag/ThreeDiag.cpp.i"
	cd /home/kostya/ProjectForC++/SLAU/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kostya/ProjectForC++/SLAU/src/project/matrix/ThreeDiag/ThreeDiag.cpp > CMakeFiles/project.dir/project/matrix/ThreeDiag/ThreeDiag.cpp.i

src/CMakeFiles/project.dir/project/matrix/ThreeDiag/ThreeDiag.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project.dir/project/matrix/ThreeDiag/ThreeDiag.cpp.s"
	cd /home/kostya/ProjectForC++/SLAU/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kostya/ProjectForC++/SLAU/src/project/matrix/ThreeDiag/ThreeDiag.cpp -o CMakeFiles/project.dir/project/matrix/ThreeDiag/ThreeDiag.cpp.s

src/CMakeFiles/project.dir/project/matrix/dense/dense.cpp.o: src/CMakeFiles/project.dir/flags.make
src/CMakeFiles/project.dir/project/matrix/dense/dense.cpp.o: ../src/project/matrix/dense/dense.cpp
src/CMakeFiles/project.dir/project/matrix/dense/dense.cpp.o: src/CMakeFiles/project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kostya/ProjectForC++/SLAU/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/project.dir/project/matrix/dense/dense.cpp.o"
	cd /home/kostya/ProjectForC++/SLAU/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/project.dir/project/matrix/dense/dense.cpp.o -MF CMakeFiles/project.dir/project/matrix/dense/dense.cpp.o.d -o CMakeFiles/project.dir/project/matrix/dense/dense.cpp.o -c /home/kostya/ProjectForC++/SLAU/src/project/matrix/dense/dense.cpp

src/CMakeFiles/project.dir/project/matrix/dense/dense.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project.dir/project/matrix/dense/dense.cpp.i"
	cd /home/kostya/ProjectForC++/SLAU/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kostya/ProjectForC++/SLAU/src/project/matrix/dense/dense.cpp > CMakeFiles/project.dir/project/matrix/dense/dense.cpp.i

src/CMakeFiles/project.dir/project/matrix/dense/dense.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project.dir/project/matrix/dense/dense.cpp.s"
	cd /home/kostya/ProjectForC++/SLAU/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kostya/ProjectForC++/SLAU/src/project/matrix/dense/dense.cpp -o CMakeFiles/project.dir/project/matrix/dense/dense.cpp.s

src/CMakeFiles/project.dir/project/solver/sweepMethod.cpp.o: src/CMakeFiles/project.dir/flags.make
src/CMakeFiles/project.dir/project/solver/sweepMethod.cpp.o: ../src/project/solver/sweepMethod.cpp
src/CMakeFiles/project.dir/project/solver/sweepMethod.cpp.o: src/CMakeFiles/project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kostya/ProjectForC++/SLAU/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/project.dir/project/solver/sweepMethod.cpp.o"
	cd /home/kostya/ProjectForC++/SLAU/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/project.dir/project/solver/sweepMethod.cpp.o -MF CMakeFiles/project.dir/project/solver/sweepMethod.cpp.o.d -o CMakeFiles/project.dir/project/solver/sweepMethod.cpp.o -c /home/kostya/ProjectForC++/SLAU/src/project/solver/sweepMethod.cpp

src/CMakeFiles/project.dir/project/solver/sweepMethod.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project.dir/project/solver/sweepMethod.cpp.i"
	cd /home/kostya/ProjectForC++/SLAU/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kostya/ProjectForC++/SLAU/src/project/solver/sweepMethod.cpp > CMakeFiles/project.dir/project/solver/sweepMethod.cpp.i

src/CMakeFiles/project.dir/project/solver/sweepMethod.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project.dir/project/solver/sweepMethod.cpp.s"
	cd /home/kostya/ProjectForC++/SLAU/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kostya/ProjectForC++/SLAU/src/project/solver/sweepMethod.cpp -o CMakeFiles/project.dir/project/solver/sweepMethod.cpp.s

# Object files for target project
project_OBJECTS = \
"CMakeFiles/project.dir/project/containers/vector.cpp.o" \
"CMakeFiles/project.dir/project/matrix/CSR/CSR.cpp.o" \
"CMakeFiles/project.dir/project/matrix/ThreeDiag/ThreeDiag.cpp.o" \
"CMakeFiles/project.dir/project/matrix/dense/dense.cpp.o" \
"CMakeFiles/project.dir/project/solver/sweepMethod.cpp.o"

# External object files for target project
project_EXTERNAL_OBJECTS =

src/libproject.a: src/CMakeFiles/project.dir/project/containers/vector.cpp.o
src/libproject.a: src/CMakeFiles/project.dir/project/matrix/CSR/CSR.cpp.o
src/libproject.a: src/CMakeFiles/project.dir/project/matrix/ThreeDiag/ThreeDiag.cpp.o
src/libproject.a: src/CMakeFiles/project.dir/project/matrix/dense/dense.cpp.o
src/libproject.a: src/CMakeFiles/project.dir/project/solver/sweepMethod.cpp.o
src/libproject.a: src/CMakeFiles/project.dir/build.make
src/libproject.a: src/CMakeFiles/project.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kostya/ProjectForC++/SLAU/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX static library libproject.a"
	cd /home/kostya/ProjectForC++/SLAU/build/src && $(CMAKE_COMMAND) -P CMakeFiles/project.dir/cmake_clean_target.cmake
	cd /home/kostya/ProjectForC++/SLAU/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/project.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/project.dir/build: src/libproject.a
.PHONY : src/CMakeFiles/project.dir/build

src/CMakeFiles/project.dir/clean:
	cd /home/kostya/ProjectForC++/SLAU/build/src && $(CMAKE_COMMAND) -P CMakeFiles/project.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/project.dir/clean

src/CMakeFiles/project.dir/depend:
	cd /home/kostya/ProjectForC++/SLAU/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kostya/ProjectForC++/SLAU /home/kostya/ProjectForC++/SLAU/src /home/kostya/ProjectForC++/SLAU/build /home/kostya/ProjectForC++/SLAU/build/src /home/kostya/ProjectForC++/SLAU/build/src/CMakeFiles/project.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/project.dir/depend
