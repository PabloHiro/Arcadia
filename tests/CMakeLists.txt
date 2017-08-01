
cmake_minimum_required (VERSION 2.8)

#----------------------------------------
#        project name

project(Arcadia)

include_directories("..")
include_directories("${PROJECT_BINARY_DIR}")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -static-libgcc -static-libstdc++")

set ( SRC_FILES
    ../src/bear.cpp
    ../src/bear.hpp
    ../src/stat.cpp
    ../src/stat.hpp
    ../src/team.cpp
    ../src/team.hpp
    ../src/unit.cpp
    ../src/unit.hpp
    ../src/buff.cpp
    ../src/buff.hpp
)

add_executable( bear test0.cpp ${SRC_FILES})
