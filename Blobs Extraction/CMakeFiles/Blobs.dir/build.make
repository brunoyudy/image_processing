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
CMAKE_SOURCE_DIR = "/home/yudy/Desktop/Image_processing/Blobs Analysis/Blobs Extraction"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/yudy/Desktop/Image_processing/Blobs Analysis/Blobs Extraction"

# Include any dependencies generated for this target.
include CMakeFiles/Blobs.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Blobs.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Blobs.dir/flags.make

CMakeFiles/Blobs.dir/blob_detector.cpp.o: CMakeFiles/Blobs.dir/flags.make
CMakeFiles/Blobs.dir/blob_detector.cpp.o: blob_detector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/yudy/Desktop/Image_processing/Blobs Analysis/Blobs Extraction/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Blobs.dir/blob_detector.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Blobs.dir/blob_detector.cpp.o -c "/home/yudy/Desktop/Image_processing/Blobs Analysis/Blobs Extraction/blob_detector.cpp"

CMakeFiles/Blobs.dir/blob_detector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Blobs.dir/blob_detector.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/yudy/Desktop/Image_processing/Blobs Analysis/Blobs Extraction/blob_detector.cpp" > CMakeFiles/Blobs.dir/blob_detector.cpp.i

CMakeFiles/Blobs.dir/blob_detector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Blobs.dir/blob_detector.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/yudy/Desktop/Image_processing/Blobs Analysis/Blobs Extraction/blob_detector.cpp" -o CMakeFiles/Blobs.dir/blob_detector.cpp.s

CMakeFiles/Blobs.dir/blob_detector.cpp.o.requires:

.PHONY : CMakeFiles/Blobs.dir/blob_detector.cpp.o.requires

CMakeFiles/Blobs.dir/blob_detector.cpp.o.provides: CMakeFiles/Blobs.dir/blob_detector.cpp.o.requires
	$(MAKE) -f CMakeFiles/Blobs.dir/build.make CMakeFiles/Blobs.dir/blob_detector.cpp.o.provides.build
.PHONY : CMakeFiles/Blobs.dir/blob_detector.cpp.o.provides

CMakeFiles/Blobs.dir/blob_detector.cpp.o.provides.build: CMakeFiles/Blobs.dir/blob_detector.cpp.o


# Object files for target Blobs
Blobs_OBJECTS = \
"CMakeFiles/Blobs.dir/blob_detector.cpp.o"

# External object files for target Blobs
Blobs_EXTERNAL_OBJECTS =

Blobs: CMakeFiles/Blobs.dir/blob_detector.cpp.o
Blobs: CMakeFiles/Blobs.dir/build.make
Blobs: /usr/local/lib/libopencv_stitching.so.4.3.0
Blobs: /usr/local/lib/libopencv_highgui.so.4.3.0
Blobs: /usr/local/lib/libopencv_objdetect.so.4.3.0
Blobs: /usr/local/lib/libopencv_dnn.so.4.3.0
Blobs: /usr/local/lib/libopencv_ml.so.4.3.0
Blobs: /usr/local/lib/libopencv_photo.so.4.3.0
Blobs: /usr/local/lib/libopencv_gapi.so.4.3.0
Blobs: /usr/local/lib/libopencv_videoio.so.4.3.0
Blobs: /usr/local/lib/libopencv_imgcodecs.so.4.3.0
Blobs: /usr/local/lib/libopencv_video.so.4.3.0
Blobs: /usr/local/lib/libopencv_calib3d.so.4.3.0
Blobs: /usr/local/lib/libopencv_features2d.so.4.3.0
Blobs: /usr/local/lib/libopencv_imgproc.so.4.3.0
Blobs: /usr/local/lib/libopencv_flann.so.4.3.0
Blobs: /usr/local/lib/libopencv_core.so.4.3.0
Blobs: CMakeFiles/Blobs.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/yudy/Desktop/Image_processing/Blobs Analysis/Blobs Extraction/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Blobs"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Blobs.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Blobs.dir/build: Blobs

.PHONY : CMakeFiles/Blobs.dir/build

CMakeFiles/Blobs.dir/requires: CMakeFiles/Blobs.dir/blob_detector.cpp.o.requires

.PHONY : CMakeFiles/Blobs.dir/requires

CMakeFiles/Blobs.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Blobs.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Blobs.dir/clean

CMakeFiles/Blobs.dir/depend:
	cd "/home/yudy/Desktop/Image_processing/Blobs Analysis/Blobs Extraction" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/yudy/Desktop/Image_processing/Blobs Analysis/Blobs Extraction" "/home/yudy/Desktop/Image_processing/Blobs Analysis/Blobs Extraction" "/home/yudy/Desktop/Image_processing/Blobs Analysis/Blobs Extraction" "/home/yudy/Desktop/Image_processing/Blobs Analysis/Blobs Extraction" "/home/yudy/Desktop/Image_processing/Blobs Analysis/Blobs Extraction/CMakeFiles/Blobs.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Blobs.dir/depend
