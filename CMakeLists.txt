cmake_minimum_required(VERSION 3.0.2)
project(seed_sample)
add_compile_options(-std=c++11)
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
  seed_smartactuator_sdk
)

## Generate services in the 'srv' folder
add_service_files(
  FILES
  RunScript.srv
)

## Generate added messages and services with any dependencies listed here
generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES seed_sample
#  CATKIN_DEPENDS rospy std_msgs
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

# Executable
add_executable(cpp_sample_node2 src/cpp_sample2.cpp)
target_link_libraries(cpp_sample_node2 ${catkin_LIBRARIES} )
