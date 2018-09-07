cmake_minimum_required(VERSION 3.8)
project(CoinExample)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Coin.cpp Coin.h)
add_executable(CoinExample ${SOURCE_FILES})