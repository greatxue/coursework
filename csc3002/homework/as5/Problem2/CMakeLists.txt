cmake_minimum_required(VERSION 3.25)
project(Problem2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Problem2
        lib.cpp
        lib.h
        PriorityQueue.cpp
        priorityqueue.h)
