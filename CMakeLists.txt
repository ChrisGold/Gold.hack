cmake_minimum_required(VERSION 3.10)
project(Gold_hack)

set(CMAKE_CXX_STANDARD 17)
include(SFML.cmake)

link_directories(SFML_LIBRARY_DIR)
message(STATUS "2: SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
message(STATUS "2: SFML_LIBRARY_DIR: ${SFML_LIBRARY_DIR}")

add_executable(Gold_hack main.cpp src/Level.cpp src/Level.h src/Tile.h)
target_link_libraries (Gold_hack sfml-graphics sfml-window sfml-system)