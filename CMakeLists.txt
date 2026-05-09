cmake_minimum_required(VERSION 3.20)
project(ItemTracker)

set(CMAKE_CXX_STANDARD 23)

find_package(FLTK CONFIG REQUIRED)

# SQLite amalgamation
add_library(sqlite3 STATIC extern/sqlite3.c)
target_include_directories(sqlite3 PUBLIC extern)

if(UNIX)
    target_link_libraries(sqlite3 PUBLIC dl pthread)
endif()

add_executable(TrackerProject
    src/main.cpp
    src/ui/text.cpp
    src/ui/button.cpp
    src/ui/input.cpp
    src/testDB.cpp
    src/ui/director.cpp
)

target_include_directories(TrackerProject PRIVATE src/ src/ui src/core)
target_link_libraries(TrackerProject PRIVATE fltk sqlite3)