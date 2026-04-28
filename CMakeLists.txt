cmake_minimum_required(VERSION 3.20)
project(Tracker)

find_package(FLTK CONFIG REQUIRED)

add_executable(TrackerProject
    src/gui.cpp
    src/renderHelpers.cpp
)

target_include_directories(TrackerProject PRIVATE include/)
target_link_libraries(TrackerProject PRIVATE fltk)

set_property(TARGET TrackerProject PROPERTY CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)