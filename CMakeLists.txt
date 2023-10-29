cmake_minimum_required(VERSION 3.26)
project(gesallprov)

set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")

add_executable(gesallprov main.cpp
        parser.cpp
        parser.h)
