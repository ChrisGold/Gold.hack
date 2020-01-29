cmake_minimum_required(VERSION 3.10)
project(Gold_hack)

set(CMAKE_CXX_STANDARD 17)
include(SFML.cmake)

link_directories(SFML_LIBRARY_DIR)
message(STATUS "2: SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
message(STATUS "2: SFML_LIBRARY_DIR: ${SFML_LIBRARY_DIR}")
#message(Hello)
file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "src/*.cpp" "src/*.h" "src/*.hpp" "src/**/*.cpp" "src/**/*.h" "src/**/*.hpp")

# first we can indicate the documentation build as an option and set it to ON by default
option(BUILD_DOC "Build documentation" ON)

# check if Doxygen is installed
find_package(Doxygen)
if (DOXYGEN_FOUND)
    # set input and output files
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    # request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Doxygen build started")

    # note the option ALL which allows to build the docs together with the application
    add_custom_target(doc_doxygen ALL
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM)
else (DOXYGEN_FOUND)
    message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)

add_executable(Gold_hack main.cpp ${SOURCES})
target_link_libraries(Gold_hack sfml-graphics sfml-window sfml-system yaml-cpp stdc++fs)