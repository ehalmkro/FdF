# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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

CMakeFiles/FdF.dir/src/main.c.o: CMakeFiles/FdF.dir/flags.make
CMakeFiles/FdF.dir/src/main.c.o: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ehalmkro/hive/FdF/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/FdF.dir/src/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/FdF.dir/src/main.c.o   -c /Users/ehalmkro/hive/FdF/src/main.c

CMakeFiles/FdF.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/FdF.dir/src/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ehalmkro/hive/FdF/src/main.c > CMakeFiles/FdF.dir/src/main.c.i

CMakeFiles/FdF.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/FdF.dir/src/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ehalmkro/hive/FdF/src/main.c -o CMakeFiles/FdF.dir/src/main.c.s

CMakeFiles/FdF.dir/src/pointlist.c.o: CMakeFiles/FdF.dir/flags.make
CMakeFiles/FdF.dir/src/pointlist.c.o: ../src/pointlist.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ehalmkro/hive/FdF/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/FdF.dir/src/pointlist.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/FdF.dir/src/pointlist.c.o   -c /Users/ehalmkro/hive/FdF/src/pointlist.c

CMakeFiles/FdF.dir/src/pointlist.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/FdF.dir/src/pointlist.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ehalmkro/hive/FdF/src/pointlist.c > CMakeFiles/FdF.dir/src/pointlist.c.i

CMakeFiles/FdF.dir/src/pointlist.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/FdF.dir/src/pointlist.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ehalmkro/hive/FdF/src/pointlist.c -o CMakeFiles/FdF.dir/src/pointlist.c.s

CMakeFiles/FdF.dir/src/window.c.o: CMakeFiles/FdF.dir/flags.make
CMakeFiles/FdF.dir/src/window.c.o: ../src/window.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ehalmkro/hive/FdF/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/FdF.dir/src/window.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/FdF.dir/src/window.c.o   -c /Users/ehalmkro/hive/FdF/src/window.c

CMakeFiles/FdF.dir/src/window.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/FdF.dir/src/window.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ehalmkro/hive/FdF/src/window.c > CMakeFiles/FdF.dir/src/window.c.i

CMakeFiles/FdF.dir/src/window.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/FdF.dir/src/window.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ehalmkro/hive/FdF/src/window.c -o CMakeFiles/FdF.dir/src/window.c.s

CMakeFiles/FdF.dir/src/tools.c.o: CMakeFiles/FdF.dir/flags.make
CMakeFiles/FdF.dir/src/tools.c.o: ../src/tools.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ehalmkro/hive/FdF/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/FdF.dir/src/tools.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/FdF.dir/src/tools.c.o   -c /Users/ehalmkro/hive/FdF/src/tools.c

CMakeFiles/FdF.dir/src/tools.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/FdF.dir/src/tools.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ehalmkro/hive/FdF/src/tools.c > CMakeFiles/FdF.dir/src/tools.c.i

CMakeFiles/FdF.dir/src/tools.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/FdF.dir/src/tools.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ehalmkro/hive/FdF/src/tools.c -o CMakeFiles/FdF.dir/src/tools.c.s

CMakeFiles/FdF.dir/src/color.c.o: CMakeFiles/FdF.dir/flags.make
CMakeFiles/FdF.dir/src/color.c.o: ../src/color.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ehalmkro/hive/FdF/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/FdF.dir/src/color.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/FdF.dir/src/color.c.o   -c /Users/ehalmkro/hive/FdF/src/color.c

CMakeFiles/FdF.dir/src/color.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/FdF.dir/src/color.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ehalmkro/hive/FdF/src/color.c > CMakeFiles/FdF.dir/src/color.c.i

CMakeFiles/FdF.dir/src/color.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/FdF.dir/src/color.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ehalmkro/hive/FdF/src/color.c -o CMakeFiles/FdF.dir/src/color.c.s

CMakeFiles/FdF.dir/src/read_write.c.o: CMakeFiles/FdF.dir/flags.make
CMakeFiles/FdF.dir/src/read_write.c.o: ../src/read_write.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ehalmkro/hive/FdF/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/FdF.dir/src/read_write.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/FdF.dir/src/read_write.c.o   -c /Users/ehalmkro/hive/FdF/src/read_write.c

CMakeFiles/FdF.dir/src/read_write.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/FdF.dir/src/read_write.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ehalmkro/hive/FdF/src/read_write.c > CMakeFiles/FdF.dir/src/read_write.c.i

CMakeFiles/FdF.dir/src/read_write.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/FdF.dir/src/read_write.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ehalmkro/hive/FdF/src/read_write.c -o CMakeFiles/FdF.dir/src/read_write.c.s

CMakeFiles/FdF.dir/src/line_draw.c.o: CMakeFiles/FdF.dir/flags.make
CMakeFiles/FdF.dir/src/line_draw.c.o: ../src/line_draw.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ehalmkro/hive/FdF/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/FdF.dir/src/line_draw.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/FdF.dir/src/line_draw.c.o   -c /Users/ehalmkro/hive/FdF/src/line_draw.c

CMakeFiles/FdF.dir/src/line_draw.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/FdF.dir/src/line_draw.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ehalmkro/hive/FdF/src/line_draw.c > CMakeFiles/FdF.dir/src/line_draw.c.i

CMakeFiles/FdF.dir/src/line_draw.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/FdF.dir/src/line_draw.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ehalmkro/hive/FdF/src/line_draw.c -o CMakeFiles/FdF.dir/src/line_draw.c.s

CMakeFiles/FdF.dir/src/events.c.o: CMakeFiles/FdF.dir/flags.make
CMakeFiles/FdF.dir/src/events.c.o: ../src/events.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ehalmkro/hive/FdF/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/FdF.dir/src/events.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/FdF.dir/src/events.c.o   -c /Users/ehalmkro/hive/FdF/src/events.c

CMakeFiles/FdF.dir/src/events.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/FdF.dir/src/events.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ehalmkro/hive/FdF/src/events.c > CMakeFiles/FdF.dir/src/events.c.i

CMakeFiles/FdF.dir/src/events.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/FdF.dir/src/events.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ehalmkro/hive/FdF/src/events.c -o CMakeFiles/FdF.dir/src/events.c.s

CMakeFiles/FdF.dir/src/matrix.c.o: CMakeFiles/FdF.dir/flags.make
CMakeFiles/FdF.dir/src/matrix.c.o: ../src/matrix.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ehalmkro/hive/FdF/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/FdF.dir/src/matrix.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/FdF.dir/src/matrix.c.o   -c /Users/ehalmkro/hive/FdF/src/matrix.c

CMakeFiles/FdF.dir/src/matrix.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/FdF.dir/src/matrix.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ehalmkro/hive/FdF/src/matrix.c > CMakeFiles/FdF.dir/src/matrix.c.i

CMakeFiles/FdF.dir/src/matrix.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/FdF.dir/src/matrix.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ehalmkro/hive/FdF/src/matrix.c -o CMakeFiles/FdF.dir/src/matrix.c.s

CMakeFiles/FdF.dir/src/wu.c.o: CMakeFiles/FdF.dir/flags.make
CMakeFiles/FdF.dir/src/wu.c.o: ../src/wu.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ehalmkro/hive/FdF/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/FdF.dir/src/wu.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/FdF.dir/src/wu.c.o   -c /Users/ehalmkro/hive/FdF/src/wu.c

CMakeFiles/FdF.dir/src/wu.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/FdF.dir/src/wu.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ehalmkro/hive/FdF/src/wu.c > CMakeFiles/FdF.dir/src/wu.c.i

CMakeFiles/FdF.dir/src/wu.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/FdF.dir/src/wu.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ehalmkro/hive/FdF/src/wu.c -o CMakeFiles/FdF.dir/src/wu.c.s

CMakeFiles/FdF.dir/src/extras.c.o: CMakeFiles/FdF.dir/flags.make
CMakeFiles/FdF.dir/src/extras.c.o: ../src/extras.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ehalmkro/hive/FdF/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/FdF.dir/src/extras.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/FdF.dir/src/extras.c.o   -c /Users/ehalmkro/hive/FdF/src/extras.c

CMakeFiles/FdF.dir/src/extras.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/FdF.dir/src/extras.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ehalmkro/hive/FdF/src/extras.c > CMakeFiles/FdF.dir/src/extras.c.i

CMakeFiles/FdF.dir/src/extras.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/FdF.dir/src/extras.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ehalmkro/hive/FdF/src/extras.c -o CMakeFiles/FdF.dir/src/extras.c.s

CMakeFiles/FdF.dir/src/events_mouse.c.o: CMakeFiles/FdF.dir/flags.make
CMakeFiles/FdF.dir/src/events_mouse.c.o: ../src/events_mouse.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ehalmkro/hive/FdF/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object CMakeFiles/FdF.dir/src/events_mouse.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/FdF.dir/src/events_mouse.c.o   -c /Users/ehalmkro/hive/FdF/src/events_mouse.c

CMakeFiles/FdF.dir/src/events_mouse.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/FdF.dir/src/events_mouse.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ehalmkro/hive/FdF/src/events_mouse.c > CMakeFiles/FdF.dir/src/events_mouse.c.i

CMakeFiles/FdF.dir/src/events_mouse.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/FdF.dir/src/events_mouse.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ehalmkro/hive/FdF/src/events_mouse.c -o CMakeFiles/FdF.dir/src/events_mouse.c.s

CMakeFiles/FdF.dir/src/wu_utils.c.o: CMakeFiles/FdF.dir/flags.make
CMakeFiles/FdF.dir/src/wu_utils.c.o: ../src/wu_utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ehalmkro/hive/FdF/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building C object CMakeFiles/FdF.dir/src/wu_utils.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/FdF.dir/src/wu_utils.c.o   -c /Users/ehalmkro/hive/FdF/src/wu_utils.c

CMakeFiles/FdF.dir/src/wu_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/FdF.dir/src/wu_utils.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ehalmkro/hive/FdF/src/wu_utils.c > CMakeFiles/FdF.dir/src/wu_utils.c.i

CMakeFiles/FdF.dir/src/wu_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/FdF.dir/src/wu_utils.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ehalmkro/hive/FdF/src/wu_utils.c -o CMakeFiles/FdF.dir/src/wu_utils.c.s

# Object files for target FdF
FdF_OBJECTS = \
"CMakeFiles/FdF.dir/src/main.c.o" \
"CMakeFiles/FdF.dir/src/pointlist.c.o" \
"CMakeFiles/FdF.dir/src/window.c.o" \
"CMakeFiles/FdF.dir/src/tools.c.o" \
"CMakeFiles/FdF.dir/src/color.c.o" \
"CMakeFiles/FdF.dir/src/read_write.c.o" \
"CMakeFiles/FdF.dir/src/line_draw.c.o" \
"CMakeFiles/FdF.dir/src/events.c.o" \
"CMakeFiles/FdF.dir/src/matrix.c.o" \
"CMakeFiles/FdF.dir/src/wu.c.o" \
"CMakeFiles/FdF.dir/src/extras.c.o" \
"CMakeFiles/FdF.dir/src/events_mouse.c.o" \
"CMakeFiles/FdF.dir/src/wu_utils.c.o"

# External object files for target FdF
FdF_EXTERNAL_OBJECTS =

FdF: CMakeFiles/FdF.dir/src/main.c.o
FdF: CMakeFiles/FdF.dir/src/pointlist.c.o
FdF: CMakeFiles/FdF.dir/src/window.c.o
FdF: CMakeFiles/FdF.dir/src/tools.c.o
FdF: CMakeFiles/FdF.dir/src/color.c.o
FdF: CMakeFiles/FdF.dir/src/read_write.c.o
FdF: CMakeFiles/FdF.dir/src/line_draw.c.o
FdF: CMakeFiles/FdF.dir/src/events.c.o
FdF: CMakeFiles/FdF.dir/src/matrix.c.o
FdF: CMakeFiles/FdF.dir/src/wu.c.o
FdF: CMakeFiles/FdF.dir/src/extras.c.o
FdF: CMakeFiles/FdF.dir/src/events_mouse.c.o
FdF: CMakeFiles/FdF.dir/src/wu_utils.c.o
FdF: CMakeFiles/FdF.dir/build.make
FdF: libft.a
FdF: /usr/local/lib/libmlx.a
FdF: CMakeFiles/FdF.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ehalmkro/hive/FdF/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Linking C executable FdF"
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

