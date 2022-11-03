cmake_minimum_required(VERSION 3.23)
project(untitled1)

set(CMAKE_CXX_STANDARD 11)

add_executable(untitled1 main.cpp cmake-build-debug/Machinery.cpp cmake-build-debug/Machinery.h Machine.cpp Machine.h)
