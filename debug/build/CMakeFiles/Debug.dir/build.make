# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_SOURCE_DIR = /home/Kaka/Program/Emulator/Chip8/Version2/src/debug

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/Kaka/Program/Emulator/Chip8/Version2/src/debug/build

# Include any dependencies generated for this target.
include CMakeFiles/Debug.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Debug.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Debug.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Debug.dir/flags.make

CMakeFiles/Debug.dir/main.cpp.o: CMakeFiles/Debug.dir/flags.make
CMakeFiles/Debug.dir/main.cpp.o: /home/Kaka/Program/Emulator/Chip8/Version2/src/debug/main.cpp
CMakeFiles/Debug.dir/main.cpp.o: CMakeFiles/Debug.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/Kaka/Program/Emulator/Chip8/Version2/src/debug/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Debug.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Debug.dir/main.cpp.o -MF CMakeFiles/Debug.dir/main.cpp.o.d -o CMakeFiles/Debug.dir/main.cpp.o -c /home/Kaka/Program/Emulator/Chip8/Version2/src/debug/main.cpp

CMakeFiles/Debug.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Debug.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/Kaka/Program/Emulator/Chip8/Version2/src/debug/main.cpp > CMakeFiles/Debug.dir/main.cpp.i

CMakeFiles/Debug.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Debug.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/Kaka/Program/Emulator/Chip8/Version2/src/debug/main.cpp -o CMakeFiles/Debug.dir/main.cpp.s

CMakeFiles/Debug.dir/Test.cpp.o: CMakeFiles/Debug.dir/flags.make
CMakeFiles/Debug.dir/Test.cpp.o: /home/Kaka/Program/Emulator/Chip8/Version2/src/debug/Test.cpp
CMakeFiles/Debug.dir/Test.cpp.o: CMakeFiles/Debug.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/Kaka/Program/Emulator/Chip8/Version2/src/debug/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Debug.dir/Test.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Debug.dir/Test.cpp.o -MF CMakeFiles/Debug.dir/Test.cpp.o.d -o CMakeFiles/Debug.dir/Test.cpp.o -c /home/Kaka/Program/Emulator/Chip8/Version2/src/debug/Test.cpp

CMakeFiles/Debug.dir/Test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Debug.dir/Test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/Kaka/Program/Emulator/Chip8/Version2/src/debug/Test.cpp > CMakeFiles/Debug.dir/Test.cpp.i

CMakeFiles/Debug.dir/Test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Debug.dir/Test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/Kaka/Program/Emulator/Chip8/Version2/src/debug/Test.cpp -o CMakeFiles/Debug.dir/Test.cpp.s

CMakeFiles/Debug.dir/DebugCPU.cpp.o: CMakeFiles/Debug.dir/flags.make
CMakeFiles/Debug.dir/DebugCPU.cpp.o: /home/Kaka/Program/Emulator/Chip8/Version2/src/debug/DebugCPU.cpp
CMakeFiles/Debug.dir/DebugCPU.cpp.o: CMakeFiles/Debug.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/Kaka/Program/Emulator/Chip8/Version2/src/debug/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Debug.dir/DebugCPU.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Debug.dir/DebugCPU.cpp.o -MF CMakeFiles/Debug.dir/DebugCPU.cpp.o.d -o CMakeFiles/Debug.dir/DebugCPU.cpp.o -c /home/Kaka/Program/Emulator/Chip8/Version2/src/debug/DebugCPU.cpp

CMakeFiles/Debug.dir/DebugCPU.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Debug.dir/DebugCPU.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/Kaka/Program/Emulator/Chip8/Version2/src/debug/DebugCPU.cpp > CMakeFiles/Debug.dir/DebugCPU.cpp.i

CMakeFiles/Debug.dir/DebugCPU.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Debug.dir/DebugCPU.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/Kaka/Program/Emulator/Chip8/Version2/src/debug/DebugCPU.cpp -o CMakeFiles/Debug.dir/DebugCPU.cpp.s

CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/CPU.cpp.o: CMakeFiles/Debug.dir/flags.make
CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/CPU.cpp.o: /home/Kaka/Program/Emulator/Chip8/Version2/src/CPU.cpp
CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/CPU.cpp.o: CMakeFiles/Debug.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/Kaka/Program/Emulator/Chip8/Version2/src/debug/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/CPU.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/CPU.cpp.o -MF CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/CPU.cpp.o.d -o CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/CPU.cpp.o -c /home/Kaka/Program/Emulator/Chip8/Version2/src/CPU.cpp

CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/CPU.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/CPU.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/Kaka/Program/Emulator/Chip8/Version2/src/CPU.cpp > CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/CPU.cpp.i

CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/CPU.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/CPU.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/Kaka/Program/Emulator/Chip8/Version2/src/CPU.cpp -o CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/CPU.cpp.s

CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/MMU.cpp.o: CMakeFiles/Debug.dir/flags.make
CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/MMU.cpp.o: /home/Kaka/Program/Emulator/Chip8/Version2/src/MMU.cpp
CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/MMU.cpp.o: CMakeFiles/Debug.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/Kaka/Program/Emulator/Chip8/Version2/src/debug/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/MMU.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/MMU.cpp.o -MF CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/MMU.cpp.o.d -o CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/MMU.cpp.o -c /home/Kaka/Program/Emulator/Chip8/Version2/src/MMU.cpp

CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/MMU.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/MMU.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/Kaka/Program/Emulator/Chip8/Version2/src/MMU.cpp > CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/MMU.cpp.i

CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/MMU.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/MMU.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/Kaka/Program/Emulator/Chip8/Version2/src/MMU.cpp -o CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/MMU.cpp.s

CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/PixelBuffer.cpp.o: CMakeFiles/Debug.dir/flags.make
CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/PixelBuffer.cpp.o: /home/Kaka/Program/Emulator/Chip8/Version2/src/PixelBuffer.cpp
CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/PixelBuffer.cpp.o: CMakeFiles/Debug.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/Kaka/Program/Emulator/Chip8/Version2/src/debug/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/PixelBuffer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/PixelBuffer.cpp.o -MF CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/PixelBuffer.cpp.o.d -o CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/PixelBuffer.cpp.o -c /home/Kaka/Program/Emulator/Chip8/Version2/src/PixelBuffer.cpp

CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/PixelBuffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/PixelBuffer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/Kaka/Program/Emulator/Chip8/Version2/src/PixelBuffer.cpp > CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/PixelBuffer.cpp.i

CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/PixelBuffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/PixelBuffer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/Kaka/Program/Emulator/Chip8/Version2/src/PixelBuffer.cpp -o CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/PixelBuffer.cpp.s

CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/System.cpp.o: CMakeFiles/Debug.dir/flags.make
CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/System.cpp.o: /home/Kaka/Program/Emulator/Chip8/Version2/src/System.cpp
CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/System.cpp.o: CMakeFiles/Debug.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/Kaka/Program/Emulator/Chip8/Version2/src/debug/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/System.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/System.cpp.o -MF CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/System.cpp.o.d -o CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/System.cpp.o -c /home/Kaka/Program/Emulator/Chip8/Version2/src/System.cpp

CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/System.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/System.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/Kaka/Program/Emulator/Chip8/Version2/src/System.cpp > CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/System.cpp.i

CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/System.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/System.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/Kaka/Program/Emulator/Chip8/Version2/src/System.cpp -o CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/System.cpp.s

# Object files for target Debug
Debug_OBJECTS = \
"CMakeFiles/Debug.dir/main.cpp.o" \
"CMakeFiles/Debug.dir/Test.cpp.o" \
"CMakeFiles/Debug.dir/DebugCPU.cpp.o" \
"CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/CPU.cpp.o" \
"CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/MMU.cpp.o" \
"CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/PixelBuffer.cpp.o" \
"CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/System.cpp.o"

# External object files for target Debug
Debug_EXTERNAL_OBJECTS =

Debug: CMakeFiles/Debug.dir/main.cpp.o
Debug: CMakeFiles/Debug.dir/Test.cpp.o
Debug: CMakeFiles/Debug.dir/DebugCPU.cpp.o
Debug: CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/CPU.cpp.o
Debug: CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/MMU.cpp.o
Debug: CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/PixelBuffer.cpp.o
Debug: CMakeFiles/Debug.dir/home/Kaka/Program/Emulator/Chip8/Version2/src/System.cpp.o
Debug: CMakeFiles/Debug.dir/build.make
Debug: CMakeFiles/Debug.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/Kaka/Program/Emulator/Chip8/Version2/src/debug/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable Debug"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Debug.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Debug.dir/build: Debug
.PHONY : CMakeFiles/Debug.dir/build

CMakeFiles/Debug.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Debug.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Debug.dir/clean

CMakeFiles/Debug.dir/depend:
	cd /home/Kaka/Program/Emulator/Chip8/Version2/src/debug/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/Kaka/Program/Emulator/Chip8/Version2/src/debug /home/Kaka/Program/Emulator/Chip8/Version2/src/debug /home/Kaka/Program/Emulator/Chip8/Version2/src/debug/build /home/Kaka/Program/Emulator/Chip8/Version2/src/debug/build /home/Kaka/Program/Emulator/Chip8/Version2/src/debug/build/CMakeFiles/Debug.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Debug.dir/depend

