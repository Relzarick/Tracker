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
    src/app/startup.cpp
    src/ui/director.cpp
    src/ui/input_mediator.cpp
    src/database/database.cpp
    src/ui/builders/text.cpp
    src/ui/builders/input.cpp
    src/ui/builders/button.cpp
)

target_include_directories(TrackerProject PRIVATE
    src/app
    src/core
    src/database
    src/ui
    src/ui/builders
    src/ui/widgets
)

target_link_libraries(TrackerProject PRIVATE fltk fltk_images sqlite3)