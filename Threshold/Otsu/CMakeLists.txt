cmake_minimum_required(VERSION 2.8)
project( Otsu )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( Otsu otsu.cpp )
target_link_libraries( Otsu ${OpenCV_LIBS} )

