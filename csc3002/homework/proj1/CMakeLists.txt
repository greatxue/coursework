cmake_minimum_required(VERSION 3.25)
project(proj1)
find_package(OpenCV REQUIRED)
set(CMAKE_CXX_STANDARD 17)

add_executable(proj1 predict.cpp read_mnist.h read_mnist.cpp predict.h)
target_link_libraries(proj1 ${OpenCV_LIBRARIES})
