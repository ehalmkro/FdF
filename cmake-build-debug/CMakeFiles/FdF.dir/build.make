# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ehalmkro/hive/FdF

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ehalmkro/hive/FdF/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/FdF.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/FdF.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FdF.dir/flags.make

CMakeFiles/FdF.dir/main.c.o: CMakeFiles/FdF.dir/flags.make
CMakeFiles/FdF.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ehalmkro/hive/FdF/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/FdF.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/FdF.dir/main.c.o   -c /Users/ehalmkro/hive/FdF/main.c

CMakeFiles/FdF.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/FdF.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ehalmkro/hive/FdF/main.c > CMakeFiles/FdF.dir/main.c.i

CMakeFiles/FdF.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/FdF.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ehalmkro/hive/FdF/main.c -o CMakeFiles/FdF.dir/main.c.s

CMakeFiles/FdF.dir/pointlist.c.o: CMakeFiles/FdF.dir/flags.make
CMakeFiles/FdF.dir/pointlist.c.o: ../pointlist.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ehalmkro/hive/FdF/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/FdF.dir/pointlist.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/FdF.dir/pointlist.c.o   -c /Users/ehalmkro/hive/FdF/pointlist.c

CMakeFiles/FdF.dir/pointlist.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/FdF.dir/pointlist.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ehalmkro/hive/FdF/pointlist.c > CMakeFiles/FdF.dir/pointlist.c.i

CMakeFiles/FdF.dir/pointlist.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/FdF.dir/pointlist.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ehalmkro/hive/FdF/pointlist.c -o CMakeFiles/FdF.dir/pointlist.c.s

CMakeFiles/FdF.dir/draw_window.c.o: CMakeFiles/FdF.dir/flags.make
CMakeFiles/FdF.dir/draw_window.c.o: ../draw_window.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ehalmkro/hive/FdF/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/FdF.dir/draw_window.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/FdF.dir/draw_window.c.o   -c /Users/ehalmkro/hive/FdF/draw_window.c

CMakeFiles/FdF.dir/draw_window.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/FdF.dir/draw_window.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ehalmkro/hive/FdF/draw_window.c > CMakeFiles/FdF.dir/draw_window.c.i

CMakeFiles/FdF.dir/draw_window.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/FdF.dir/draw_window.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ehalmkro/hive/FdF/draw_window.c -o CMakeFiles/FdF.dir/draw_window.c.s

CMakeFiles/FdF.dir/tools.c.o: CMakeFiles/FdF.dir/flags.make
CMakeFiles/FdF.dir/tools.c.o: ../tools.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ehalmkro/hive/FdF/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/FdF.dir/tools.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/FdF.dir/tools.c.o   -c /Users/ehalmkro/hive/FdF/tools.c

CMakeFiles/FdF.dir/tools.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/FdF.dir/tools.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ehalmkro/hive/FdF/tools.c > CMakeFiles/FdF.dir/tools.c.i

CMakeFiles/FdF.dir/tools.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/FdF.dir/tools.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ehalmkro/hive/FdF/tools.c -o CMakeFiles/FdF.dir/tools.c.s

CMakeFiles/FdF.dir/color.c.o: CMakeFiles/FdF.dir/flags.make
CMakeFiles/FdF.dir/color.c.o: ../color.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ehalmkro/hive/FdF/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/FdF.dir/color.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/FdF.dir/color.c.o   -c /Users/ehalmkro/hive/FdF/color.c

CMakeFiles/FdF.dir/color.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/FdF.dir/color.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ehalmkro/hive/FdF/color.c > CMakeFiles/FdF.dir/color.c.i

CMakeFiles/FdF.dir/color.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/FdF.dir/color.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ehalmkro/hive/FdF/color.c -o CMakeFiles/FdF.dir/color.c.s

# Object files for target FdF
FdF_OBJECTS = \
"CMakeFiles/FdF.dir/main.c.o" \
"CMakeFiles/FdF.dir/pointlist.c.o" \
"CMakeFiles/FdF.dir/draw_window.c.o" \
"CMakeFiles/FdF.dir/tools.c.o" \
"CMakeFiles/FdF.dir/color.c.o"

# External object files for target FdF
FdF_EXTERNAL_OBJECTS =

FdF: CMakeFiles/FdF.dir/main.c.o
FdF: CMakeFiles/FdF.dir/pointlist.c.o
FdF: CMakeFiles/FdF.dir/draw_window.c.o
FdF: CMakeFiles/FdF.dir/tools.c.o
FdF: CMakeFiles/FdF.dir/color.c.o
FdF: CMakeFiles/FdF.dir/build.make
FdF: libft.a
FdF: /usr/local/lib/libmlx.a
FdF: CMakeFiles/FdF.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ehalmkro/hive/FdF/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable FdF"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FdF.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FdF.dir/build: FdF

.PHONY : CMakeFiles/FdF.dir/build

CMakeFiles/FdF.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/FdF.dir/cmake_clean.cmake
.PHONY : CMakeFiles/FdF.dir/clean

CMakeFiles/FdF.dir/depend:
	cd /Users/ehalmkro/hive/FdF/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ehalmkro/hive/FdF /Users/ehalmkro/hive/FdF /Users/ehalmkro/hive/FdF/cmake-build-debug /Users/ehalmkro/hive/FdF/cmake-build-debug /Users/ehalmkro/hive/FdF/cmake-build-debug/CMakeFiles/FdF.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/FdF.dir/depend

