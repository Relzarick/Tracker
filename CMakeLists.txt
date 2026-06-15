cmake_minimum_required(VERSION 3.20)
project(ItemTracker)

# -------------------------------------------------------
# C++ standard
# -------------------------------------------------------
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# -------------------------------------------------------
# FLTK via FetchContent
#
# This downloads FLTK 1.4.5 at configure time and builds
#
# The three cache variables disable parts of the FLTK build
#   FLTK_BUILD_TEST    - unit tests for FLTK itself
#   FLTK_BUILD_FLUID   - the FLTK GUI designer tool
#   FLTK_BUILD_FLTK_OPTIONS - an FLTK settings utility
# -------------------------------------------------------
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

# -------------------------------------------------------
# SQLite amalgamation
#
# The compile definitions are optional tuning:
#   SQLITE_THREADSAFE=1   - explicit (it's the default).
#                           Safe for multi-threaded use.
#   SQLITE_DQS=0          - disables double-quoted string
#                           literals, which are an SQLite
#                           quirk that hides typos in column
#                           names. Good to turn off.
#   SQLITE_DEFAULT_MEMSTATUS=0 - disables memory usage
#                           tracking. Faster if you don't
#                           need sqlite3_memory_used().
# -------------------------------------------------------
add_library(sqlite3 STATIC extern/sqlite3.c)

target_include_directories(sqlite3 PUBLIC extern)

target_compile_definitions(sqlite3 PRIVATE
    SQLITE_THREADSAFE=1
    SQLITE_DQS=0
    SQLITE_DEFAULT_MEMSTATUS=0
)

if(UNIX)
    target_link_libraries(sqlite3 PUBLIC dl pthread)
endif()

# -------------------------------------------------------
# Main executable
# -------------------------------------------------------
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

# -------------------------------------------------------
# Windows-specific settings
#
# WIN32 in add_executable tells the linker to build a
# Windows GUI application (subsystem:windows). Without it,
# Windows opens a console window behind your app.
# Note: this must be set at add_executable time, not after.
# We use set_target_properties here because the executable
# is already defined above and we want to keep the source
# list readable.
#
# comctl32 is a Windows system library FLTK's backend
# needs for native controls (buttons, scrollbars, etc).
# It's always present on Windows — you just have to ask for it.
# -------------------------------------------------------
if(WIN32)
    set_target_properties(TrackerProject PROPERTIES
        WIN32_EXECUTABLE TRUE
    )
    target_link_libraries(TrackerProject PRIVATE comctl32)
endif()

target_link_libraries(TrackerProject PRIVATE fltk fltk_images sqlite3)