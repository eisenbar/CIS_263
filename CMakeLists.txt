cmake_minimum_required(VERSION 3.8)
project(hw4)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES hw04_01.cpp BinarySearchTree.h catch.hpp WordSearch.cpp FileSystem.cpp FileSystem.h WordSearch.cpp WordSearch.h)

add_executable(part1 hw04_01.cpp)
add_executable(part2 hw04_02.cpp WordSearch.cpp FileSystem.cpp)
