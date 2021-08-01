cmake_minimum_required(VERSION 3.1)
project(FuckingAlgorithm)
set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(FuckingAlgorithm main.cpp tree/94.cc tree/100.cc tree/101.cc tree/104.cc tree/111.cc tree/144.cc tree/112.cc disjoint-set/P1551.cc disjoint-set/547.cc tree/102.cc tree/107.cc tree/114.cc include/NestedInteger.h tree/341.cc tree/222.cc dp/70.cc trick/p1226.cc others/5830.cc dp/55.cc)

target_link_libraries(FuckingAlgorithm gtest pthread)