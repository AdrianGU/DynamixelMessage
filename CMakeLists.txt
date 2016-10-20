cmake_minimum_required(VERSION 3.6)
project(OOP_Teensy)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES DynamixelMessage.h DynamixelMessage.cpp)
add_executable(OOP_Teensy ${SOURCE_FILES})