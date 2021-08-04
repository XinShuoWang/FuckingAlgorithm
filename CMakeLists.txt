cmake_minimum_required(VERSION 3.1)
project(FuckingAlgorithm)
set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(FuckingAlgorithm
        main.cpp
        tree/94.cc
        tree/100.cc
        tree/101.cc
        tree/104.cc
        tree/111.cc
        tree/144.cc
        tree/112.cc
        disjoint-set/P1551.cc
        disjoint-set/547.cc
        tree/102.cc
        tree/107.cc
        tree/114.cc
        tree/341.cc
        tree/222.cc
        dp/70.cc
        trick/p1226.cc
        others/5830.cc
        dp/55.cc
        tree/98.cc
        tree/113.cc
        tree/513.cc
        backtrace/46.cc
        others/66.cc
        others/566.cc
        others/67.cc
        others/20.cc
        tree/108.cc
        tree/145.cc
        tree/872.cc
        tree/559.cc
        tree/589.cc
        tree/590.cc
        tree/814.cc
        tree/226.cc
        tree/257.cc
        tree/235.cc
        tree/404.cc tree/m0404.cc tree/543.cc tree/501.cc dp/53.cc dp/152.cc dp/jz10.cc tree/m0405.cc)

target_link_libraries(FuckingAlgorithm gtest pthread)