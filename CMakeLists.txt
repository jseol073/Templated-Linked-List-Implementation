SET(CMAKE_C_COMPILER gcc)
SET(CMAKE_CXX_COMPILER g++)
cmake_minimum_required(VERSION 3.5)
project(snake-linked-list)
set(CMAKE_CXX_STANDARD 14)

add_executable(unit-tests test/test.cpp test/catch.hpp src/ll.h src/snakebody.cpp src/snakebody.h)
