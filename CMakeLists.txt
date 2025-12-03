cmake_minimum_required(VERSION 3.10)

# Project name
project(AgendaApp)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS False)

# Set output directory for binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Include directories
include_directories(include)
include_directories(interfaces)
include_directories(include/Agenda)
include_directories(include/Events)
include_directories(include/Timestamp)
include_directories(include/statemachine)
include_directories(include/statemachine/states)


# Collect all source files from subdirectories
file(GLOB_RECURSE SOURCES 
    "src/*.cpp"    
    "src/statemachine/*.cpp"
    "src/Agenda/*.cpp"
    "src/Events/*.cpp"
    "src/Menu/*.cpp"
    "src/Timestamp/*.cpp"
)

# Create the executable
add_executable(AgendaApp ${SOURCES})

# Compilation options
target_compile_options(AgendaApp PRIVATE -Wall -Wextra -pedantic)
