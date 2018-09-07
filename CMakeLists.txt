cmake_minimum_required(VERSION 3.8)
project(hw01_date)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES hw01-date.cpp SimpleDate.cpp SimpleDate.h)
add_executable(hw01_date ${SOURCE_FILES})