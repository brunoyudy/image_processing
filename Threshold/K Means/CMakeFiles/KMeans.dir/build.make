# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/yudy/Desktop/Chapter_1/K Means"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/yudy/Desktop/Chapter_1/K Means"

# Include any dependencies generated for this target.
include CMakeFiles/KMeans.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/KMeans.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/KMeans.dir/flags.make

CMakeFiles/KMeans.dir/k_means.cpp.o: CMakeFiles/KMeans.dir/flags.make
CMakeFiles/KMeans.dir/k_means.cpp.o: k_means.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/yudy/Desktop/Chapter_1/K Means/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/KMeans.dir/k_means.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/KMeans.dir/k_means.cpp.o -c "/home/yudy/Desktop/Chapter_1/K Means/k_means.cpp"

CMakeFiles/KMeans.dir/k_means.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/KMeans.dir/k_means.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/yudy/Desktop/Chapter_1/K Means/k_means.cpp" > CMakeFiles/KMeans.dir/k_means.cpp.i

CMakeFiles/KMeans.dir/k_means.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/KMeans.dir/k_means.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/yudy/Desktop/Chapter_1/K Means/k_means.cpp" -o CMakeFiles/KMeans.dir/k_means.cpp.s

CMakeFiles/KMeans.dir/k_means.cpp.o.requires:

.PHONY : CMakeFiles/KMeans.dir/k_means.cpp.o.requires

CMakeFiles/KMeans.dir/k_means.cpp.o.provides: CMakeFiles/KMeans.dir/k_means.cpp.o.requires
	$(MAKE) -f CMakeFiles/KMeans.dir/build.make CMakeFiles/KMeans.dir/k_means.cpp.o.provides.build
.PHONY : CMakeFiles/KMeans.dir/k_means.cpp.o.provides

CMakeFiles/KMeans.dir/k_means.cpp.o.provides.build: CMakeFiles/KMeans.dir/k_means.cpp.o


# Object files for target KMeans
KMeans_OBJECTS = \
"CMakeFiles/KMeans.dir/k_means.cpp.o"

# External object files for target KMeans
KMeans_EXTERNAL_OBJECTS =

KMeans: CMakeFiles/KMeans.dir/k_means.cpp.o
KMeans: CMakeFiles/KMeans.dir/build.make
KMeans: /usr/local/lib/libopencv_stitching.so.4.3.0
KMeans: /usr/local/lib/libopencv_highgui.so.4.3.0
KMeans: /usr/local/lib/libopencv_objdetect.so.4.3.0
KMeans: /usr/local/lib/libopencv_dnn.so.4.3.0
KMeans: /usr/local/lib/libopencv_ml.so.4.3.0
KMeans: /usr/local/lib/libopencv_photo.so.4.3.0
KMeans: /usr/local/lib/libopencv_gapi.so.4.3.0
KMeans: /usr/local/lib/libopencv_videoio.so.4.3.0
KMeans: /usr/local/lib/libopencv_imgcodecs.so.4.3.0
KMeans: /usr/local/lib/libopencv_video.so.4.3.0
KMeans: /usr/local/lib/libopencv_calib3d.so.4.3.0
KMeans: /usr/local/lib/libopencv_features2d.so.4.3.0
KMeans: /usr/local/lib/libopencv_imgproc.so.4.3.0
KMeans: /usr/local/lib/libopencv_flann.so.4.3.0
KMeans: /usr/local/lib/libopencv_core.so.4.3.0
KMeans: CMakeFiles/KMeans.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/yudy/Desktop/Chapter_1/K Means/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable KMeans"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/KMeans.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/KMeans.dir/build: KMeans

.PHONY : CMakeFiles/KMeans.dir/build

CMakeFiles/KMeans.dir/requires: CMakeFiles/KMeans.dir/k_means.cpp.o.requires

.PHONY : CMakeFiles/KMeans.dir/requires

CMakeFiles/KMeans.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/KMeans.dir/cmake_clean.cmake
.PHONY : CMakeFiles/KMeans.dir/clean

CMakeFiles/KMeans.dir/depend:
	cd "/home/yudy/Desktop/Chapter_1/K Means" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/yudy/Desktop/Chapter_1/K Means" "/home/yudy/Desktop/Chapter_1/K Means" "/home/yudy/Desktop/Chapter_1/K Means" "/home/yudy/Desktop/Chapter_1/K Means" "/home/yudy/Desktop/Chapter_1/K Means/CMakeFiles/KMeans.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/KMeans.dir/depend
