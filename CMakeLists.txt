cmake_minimum_required(VERSION 3.1)
project(FuckingAlgorithm)
set(CMAKE_CXX_STANDARD 11)

add_executable(FuckingAlgorithm main.cpp tree/94.cc tree/100.cc)
#target_include_directories(FuckingAlgorithm PRIVATE /usr/include/gtest)
target_link_libraries(FuckingAlgorithm gtest pthread)