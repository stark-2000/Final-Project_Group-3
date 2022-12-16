cmake_minimum_required(VERSION 2.8.3)
project(swarm_robot_description)

find_package(catkin_simple REQUIRED)

catkin_simple()

cs_add_executable(two_wheel_robot_manager src/two_wheel_robot_manager.cpp)
cs_add_executable(two_wheel_robot_batch_add src/two_wheel_robot_batch_add.cpp)

cs_install()
cs_export()