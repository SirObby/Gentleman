# minimum CMake version required
cmake_minimum_required(VERSION 3.15)

project(gent)

file(GLOB_RECURSE source_list "src/*.cpp" "src/*.hpp")

add_executable(gent ${source_list})

# Set C++ version
set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17 # or 20 if you want something more recent
    CXX_STANDARD_REQUIRED ON
 )