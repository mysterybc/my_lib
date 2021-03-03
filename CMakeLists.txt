cmake_minimum_required(VERSION 3.0.2)
project(my_lib)

add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  message_generation
  actionlib
  roscpp
  tf
)

find_package(Boost REQUIRED COMPONENTS system thread)

## Generate messages in the 'msg' folder
# add_message_files(
#   FILES
#   Message1.msg
#   Message2.msg
# )

## Generate services in the 'srv' folder
# add_service_files(
#   FILES
#   Service1.srv
#   Service2.srv
# )

# Generate actions in the 'action' folder
add_action_files(
  DIRECTORY action
  FILES
  WashDish.action
)

# Generate added messages and services with any dependencies listed here
generate_messages(
  DEPENDENCIES
  std_msgs  # Or other packages containing msgs
  actionlib_msgs
)


catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES my_lib
#  CATKIN_DEPENDS actionlib roscpp tf
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(my_action_demo src/my_action_demo src/debug_info.cpp)
target_link_libraries(my_action_demo ${catkin_LIBRARIES})

