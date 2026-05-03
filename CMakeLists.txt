cmake_minimum_required(VERSION 3.20)
project(ItemTracker)

find_package(FLTK CONFIG REQUIRED)

add_executable(TrackerProject
    src/main.cpp
    src/ui/text.cpp
    src/ui/button.cpp
    src/ui/input.cpp
)

target_include_directories(TrackerProject PRIVATE src/ src/ui src/core)
target_link_libraries(TrackerProject PRIVATE fltk)

set_property(TARGET TrackerProject PROPERTY CXX_STANDARD 23)