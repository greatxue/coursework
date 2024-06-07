cmake_minimum_required(VERSION 3.25)
project(Problem1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Problem1
        lib.cpp
        lib.h
        stringmap.cpp
        stringmap.h
        tokenscanner.cpp
        tokenscanner.h)
