cmake_minimum_required(VERSION 3.20)
project(ItemTracker)

# -------------------------------------------------------
# C++ standard
# -------------------------------------------------------
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# --- FLTK ---
include(FetchContent)

set(FLTK_BUILD_TEST OFF CACHE BOOL "" FORCE)
set(FLTK_BUILD_FLUID OFF CACHE BOOL "" FORCE)
set(FLTK_BUILD_FLTK_OPTIONS OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
    fltk
    GIT_REPOSITORY https://github.com/fltk/fltk.git
    GIT_TAG        release-1.4.5
    GIT_SHALLOW    TRUE
)

FetchContent_MakeAvailable(fltk)


# --- SQLite ---
add_library(sqlite3 STATIC extern/sqlite3.c)

target_include_directories(sqlite3 PUBLIC extern)
target_compile_definitions(sqlite3 PRIVATE
    SQLITE_THREADSAFE=1
    SQLITE_DQS=0
    SQLITE_DEFAULT_MEMSTATUS=0
)

target_compile_definitions(sqlite3 PRIVATE
    SQLITE_THREADSAFE=1
    SQLITE_DQS=0
    SQLITE_DEFAULT_MEMSTATUS=0
)

if(UNIX)
    target_link_libraries(sqlite3 PUBLIC dl pthread)
endif()

# --- App ---
add_executable(TrackerProject
    src/main.cpp
    src/app/startup.cpp
    src/ui/director.cpp
    src/ui/entries_mediator.cpp
    src/database/database.cpp
    src/ui/builders/text.cpp
    src/ui/builders/input.cpp
    src/ui/builders/button.cpp
    src/ui/widgets/custom_widgets.cpp
)

target_include_directories(TrackerProject PRIVATE
    src/app
    src/core
    src/database
    src/ui
    src/ui/builders
    src/ui/widgets
)

if(WIN32)
    set_target_properties(TrackerProject PROPERTIES WIN32_EXECUTABLE TRUE)
    target_link_libraries(TrackerProject PRIVATE comctl32)
endif()

target_link_libraries(TrackerProject PRIVATE fltk fltk_images sqlite3)
