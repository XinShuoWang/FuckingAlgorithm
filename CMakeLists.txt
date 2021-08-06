cmake_minimum_required(VERSION 3.1)
project(FuckingAlgorithm)
set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(FuckingAlgorithm
        main.cpp
        src/tree/94.cc
        src/tree/100.cc
        src/tree/101.cc
        src/tree/104.cc
        src/tree/111.cc
        src/tree/144.cc
        src/tree/112.cc
        src/disjoint-set/P1551.cc
        src/disjoint-set/547.cc
        src/tree/102.cc
        src/tree/107.cc
        src/tree/114.cc
        src/tree/341.cc
        src/tree/222.cc
        src/dp/70.cc
        src/trick/p1226.cc
        src/others/5830.cc
        src/dp/55.cc
        src/tree/98.cc
        src/tree/113.cc
        src/tree/513.cc
        src/backtrace/46.cc
        src/others/66.cc
        src/others/566.cc
        src/others/67.cc
        src/others/20.cc
        src/tree/108.cc
        src/tree/145.cc
        src/tree/872.cc
        src/tree/559.cc
        src/tree/589.cc
        src/tree/590.cc
        src/tree/814.cc
        src/tree/226.cc
        src/tree/257.cc
        src/tree/235.cc
        src/tree/404.cc
        src/tree/m0404.cc
        src/tree/543.cc
        src/tree/501.cc
        src/dp/53.cc
        src/dp/152.cc
        src/dp/jz10.cc
        src/tree/m0405.cc
        src/others/146.cc src/tree/1104.cc src/tree/103.cc src/tree/105.cc src/tree/106.cc)

target_link_libraries(FuckingAlgorithm gtest pthread)