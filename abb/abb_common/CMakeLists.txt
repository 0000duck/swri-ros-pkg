cmake_minimum_required(VERSION 2.4.6)
include($ENV{ROS_ROOT}/core/rosbuild/rosbuild.cmake)

# Set the build type.  Options are:
#  Coverage       : w/ debug symbols, w/o optimization, w/ code-coverage
#  Debug          : w/ debug symbols, w/o optimization
#  Release        : w/o debug symbols, w/ optimization
#  RelWithDebInfo : w/ debug symbols, w/ optimization
#  MinSizeRel     : w/o debug symbols, w/ optimization, stripped binaries
#set(ROS_BUILD_TYPE RelWithDebInfo)

rosbuild_init()

#set the default path for built executables to the "bin" directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#set the default path for built libraries to the "lib" directory
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
#set the default path for urdf's to the "urdf" directory
set(URDF_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/urdf)

#uncomment if you have defined messages
#rosbuild_genmsg()
#uncomment if you have defined services
#rosbuild_gensrv()

#common commands for building c++ executables and libraries
#rosbuild_add_library(${PROJECT_NAME} src/example.cpp)
#target_link_libraries(${PROJECT_NAME} another_library)
#rosbuild_add_boost_directories()
#rosbuild_link_boost(${PROJECT_NAME} thread)
#rosbuild_add_executable(example examples/example.cpp)
#target_link_libraries(example ${PROJECT_NAME})

# NOTE: Building URDF files does not appear to be working
# CMakeLists example taken from http://ros.org/wiki/xacro
# Build URDF files from xacro
#rosbuild_find_ros_package(xacro)
#include(${xacro_PACKAGE_PATH}/cmake/xacro.cmake)
#message("Generating URDFs from " ${URDF_OUTPUT_PATH})
#set(IRB_INPUT ${URDF_OUTPUT_PATH}/irb_5400.xacro)
#set(IRB_OUTPUT ${URDF_OUTPUT_PATH}/irb_5400.urdf)
#message("Generating " ${IRB_OUTPUT} " from " ${IRB_INPUT})
#xacro_add_xacro_file(${IRB_INPUT} ${IRB_OUTPUT})
#message("Generated URDFs in " ${URDF_OUTPUT_PATH})
