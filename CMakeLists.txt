cmake_minimum_required(VERSION 3.20)

project(Tracker)

add_executable(TrackerProject src/gui.cpp)
target_include_directories(TrackerProject PRIVATE include/)
set_property(TARGET TrackerProject PROPERTY CXX_STANDARD 23)