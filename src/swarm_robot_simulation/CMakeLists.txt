cmake_minimum_required(VERSION 2.8.3)
project(swarm_robot_simulation)

find_package(catkin_simple REQUIRED)

catkin_simple()

cs_add_executable(two_wheel_robot_line_formation src/two_wheel_robot_line_formation.cpp)

cs_install()
cs_export()