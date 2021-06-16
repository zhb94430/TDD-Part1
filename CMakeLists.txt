cmake_minimum_required(VERSION 3.14)
project(TDD-Part1)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(./Tests)
