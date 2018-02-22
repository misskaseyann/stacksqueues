cmake_minimum_required(VERSION 3.8)
project(stacksqueues)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp include/Functions.h src/Functions.cpp)
add_executable(stacksqueues ${SOURCE_FILES})