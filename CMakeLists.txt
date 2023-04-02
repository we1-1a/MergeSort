cmake_minimum_required(VERSION 3.14)
project(Assignment4)

set(CMAKE_CXX_STANDARD 14)

add_executable(Assignment4
        src/main.cpp src/Employee.h src/Employee.cpp src/MergeSort.h src/MergeSort.cpp src/FileUtils.h src/FileUtils.cpp)
