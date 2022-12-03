[![Build Status](https://github.com/stark-2000/Final-Project_Group-3/actions/workflows/build_and_coveralls.yml/badge.svg)](https://github.com/stark-2000/Final-Project_Group-3/actions/workflows/build_and_coveralls.yml)
[![Coverage Status](https://coveralls.io/repos/github/stark-2000/Final-Project_Group-3/badge.svg?branch=main)](https://coveralls.io/github/stark-2000/Final-Project_Group-3?branch=main)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
---
# Acme's Autonomous Robot

## Disclaimer
 - License: MIT  
 - License File: LICENSE (in the project directory)
   
## Project Overview and Description:
 - For the final project, me and my teammate have decided to choose multi-robot/swarm action category for Acme’s new line up of autonomous robots. These are developed as part of a 5 year product road map for ACME in developing their fleet of autonomous. We will work on the deliverables and provide a high-quality solution following the essential software engineering practices which they can directly integrate into their product.
 - We will deploy a swarm of 21 turtlebots, which will collectively perform a task of crossing a narrow passage. Their default pattern will be a square or rectangle. 
 - Using LIDAR or 3D Camera on the leader robot, we will be checking for the narrow passage in the path of the leader robot. Once it's detected, the swarm will still move until the minimum threshold distance from the narrow passage is reached. This threshold is determined based on the no of robots in swarm and minimum space required for them to transform or deform into a specified pattern.
 - The swarm will now transform into a line segment which has all the 21 turtlebots one behind the other. Then it will move through the narrow passage.
 - LIDARs are also present on the left & right side of leader robot which will monitor for the end of narrow passage. Once the end is reached, the swarm will still continue to move until the minimum threshold distance is achieved. 
 - Now the swarm will deform into it's default shape.
 - Note that the minimum threshold distance will be determined based on the no of robots in swarm and total length and width they need if they were to form a straight line with one robot behind the other. Also the leader robot will be the one which is in the center of one of the sides of rectangle (when swarm is in default shape of rectangle or square) or it will be the first robot in line (when swarm is in a straight line - one robot behind the other). The leader robot will have 3 LIDARs or 3D camera.
 - The level of autonomy discussed may be subject to the bounds of project timeline and may be altered if required.
 - The below image is a sample representation of the swarm (for reference only):

 ![My Image](./readme_image/TurtleBot_Swarm_Sample.jpg)


## Purpose of the Project
 - The purpose this project is to deploy simple swarm algorithm on 21 turtlebots to form and deform a pattern in order to navigate a narrow passage. Sensors like LIDAR or 3D camera will be  used to realize the idea and simulate the project in Gazebo.
 
## Personnel:
 - Dhinesh Rajasekaran 
    - UID: 119400241
 - Arshad Shaik
    - UID: 118438832

## Requirements: 
 - Laptop
 - Ubuntu 22.04
 - VS Code/Terminal
 - Gazebo
 - ROS 2 Humble
 
## AIP Google Sheet
 - https://docs.google.com/spreadsheets/d/1qG9Fnqy8YEA1hoCkJ37Z2tK7iZklYtnleDhth3kJcko/edit?usp=sharing

## Shareable link to sprint planning notes and review Google Doc
 - https://docs.google.com/document/d/1eRx1KWvxIhgsw_KE1Acz5M6SJKpdceUarCSzpB1HCdQ/edit?usp=sharing
 
## Dependencies
 - doxygen (run below command to install)
   ```
   sudo apt install doxygen
   ```
 - lcov (run below command to install)
   ```
   sudo apt install lcov
   ```
## ROS msg/srv
- As per our project proposal, we are using turtlebot 3 in our project which doesn't need any additonal msg/srv to be created for the project realization. 
- In the due course of the project or during further implementation, if required, we may adapt the same code we used in Week10 HW for implementing our own msg/srv in ROS 2. 

## Sections for Stubs:
(Will be implemented by the next phase - before project implementation)

## How to build, run & test from command line
 - Run the following commands in order
(will be added in next phase)

## Command to check Google Style
- From the Final-Project_Group-3 folder src directory, run the below command
```
cpplint --filter=-build/c++11,+build/c++17,-build/namespaces,-build/include_order subscriber.cpp publisher.cpp > ./../results/cpplintreport
```
## Command to run static code analysis
- From the Final-Project_Group-3 folder src directory, run the below command
```
cppcheck --enable=all --std=c++17 *.cpp --suppress=missingIncludeSystem --suppress=missingInclude --suppress=unmatchedSuppression > ./../results/cppcheckreport
```
## Command to generatte doxygen documentation
(will be added in next phase)