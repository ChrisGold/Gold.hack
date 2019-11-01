cmake_minimum_required(VERSION 3.13)
project(Gold_hack)

set(CMAKE_CXX_STANDARD 17)
include(SFML.cmake)

add_executable(Gold_hack main.cpp src/Level.cpp src/Level.h src/Tile.h)
target_link_libraries (Gold_hack sfml-graphics sfml-window sfml-system)