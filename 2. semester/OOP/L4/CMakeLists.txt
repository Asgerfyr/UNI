cmake_minimum_required(VERSION 4.1)
project(L4)

set(CMAKE_CXX_STANDARD 20)

add_executable(L4 main.cpp
        Die.cpp
        Die.h)
