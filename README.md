[![Build Status](https://coveralls.io/repos/github/stark-2000/Final-Project_Group-3/actions/workflows/build_and_coveralls.yml/badge.svg)](https://github.com/stark-2000/Final-Project_Group-3/actions/workflows/build_and_coveralls.yml)
[![Coverage Status](https://coveralls.io/repos/github/stark-2000/Final-Project_Group-3/badge.svg?branch=main)](https://coveralls.io/github/stark-2000/Final-Project_Group-3?branch=main)
---
# Acme's Perception Robotic Module

## Disclaimer
 - License: BSD 
 - License File: LICENSE.txt (in the project directory)
   
## Project Overview and Description:
 - For the midterm project, me and my teammate have decided to choose Acme’s perception robotic module & work on the deliverables and provide a high-quality solution following the essential software engineering practices which they can directly integrate into their product.
 - Using openCV and HoG detector, humans are detected in a given frame and the head's pixel value is obtained. 
 - The result is passed on to the tracker function which compares the pixel values of detected humans with previous frame and assigns unique ID.
 - The location calculation function computes the 3D location of all detected humans in cartesian coordinates w.r.t to robot frame with some assumptions like average human height is 5ft 10", floor is flat and no camera lens distortion. 
 - This entire setup was implemented on a laptop with webcamera in real-time. After detection of humans, bounding boxes with a unique ID which was assigned by tracker function will be overlayed on video frame.
 - The below image is a sample output of the program in our project:

 ![My Image](./readme_image/output.jpg)


## Purpose of the Project
 - The purpose this project is to detect a human from the live feed from the camera and generate the co-ordinates of the location in the robot fixed frame. It shall also track the multiple human obstacles from the image.
 
## Personnel:
 - Dhinesh Rajasekaran 
    - UID: 119400241
 - Arshad Shaik
    - UID: 118438832
 
## Video Presentation:
 - https://youtu.be/AMKvC8GD-Lg - Phase 0
 - https://youtu.be/kq9s1iwcfdw - Phase 1
 - https://drive.google.com/file/d/12uLaFsCV9fPUkGabaN5A38qLslWNd6hp/view?usp=share_link - Phase 2

## Requirements: 
 - Laptop
 - Ubuntu
 - Webcam
 - VS Code
 
## AIP Google Sheet
 - https://docs.google.com/spreadsheets/d/1C9AE03gUqFlZGb2_IyPfMfevvJ9ezGKtAxI_n_HEC9M/edit?usp=sharing

## Shareable link to sprint planning notes and review Google Doc
 - https://docs.google.com/document/d/1wD_bKCtLOdt1voyiwZQc1tobgl-Iy5lTP9kQC6JQSEE/edit?usp=sharing
 
## Dependencies
 - openCV C++ library (run below command to install)
   ```
   sudo apt install libopencv-dev python3-opencv
   ```
 - doxygen (run below command to install)
   ```
   sudo apt install doxygen
   ```
 - lcov (run below command to install)
   ```
   sudo apt install lcov
   ```
   
## How to build, run & test from command line
 - Run the following commands in order
```
git clone --recursive https://github.com/stark-2000/Midterm-Project_Group-8.git
cd Midterm-Project_Group-8
mkdir build
cd build
cmake ..
make
./test/cpp-test
./app/shell-app
```
 - press any key to exit

## Command to check Google Style
- From the Midterm-Project_Group-8 folder, run the below command
```
cpplint app/main.cpp app/openCV.cpp test/main.cpp test/test.cpp include/openCV.hpp > results/cpplintreport
```
## Command to run static code analysis
- From the Midterm-Project_Group-8 folder, run the below command
```
cppcheck --enable=all --std=c++11 --suppress=missingIncludeSystem  ./app ./test > results/cppcheckreport
cppcheck --enable=all --std=c++11 --suppress=missingIncludeSystem  ./include/openCV.hpp  > results/cppcheckreport_include_files
```
## Command to check code coverage
- From the build directory run the following command
```
cmake -D COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug ../
make
make code_coverage
```
## How to generate Doxygen documentation from command line
- From the app directory run the following command
```
doxygen main.cpp
cd html
firefox index.html
```
- From the app directory run the following command
```
doxygen openCV.cpp
cd html
firefox index.html
```
- From the include directory run the following command
```
doxygen openCV.hpp
cd html
firefox index.html
```