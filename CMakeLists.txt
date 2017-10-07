# CMake
cmake_minimum_required(VERSION 3.0.0)
project (Tinycom CXX)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

SET (CMAKE_LIBRARY_OUTPUT_DIRECTORY
   ${PROJECT_BINARY_DIR}/
   CACHE PATH
   "Single Directory for all Libraries"
)
SET (CMAKE_RUNTIME_OUTPUT_DIRECTORY
   ${PROJECT_BINARY_DIR}/
   CACHE PATH
   "Single Directory for all Executables."
)
SET (CMAKE_ARCHIVE_OUTPUT_DIRECTORY
   ${PROJECT_BINARY_DIR}/
   CACHE PATH
   "Single Directory for all static libraries."
)

# Includes
include_directories(src/includes)
include_directories("${PROJECT_BINARY_DIR}")
configure_file (
    "${PROJECT_SOURCE_DIR}/src/includes/config.h.in"
    "${PROJECT_BINARY_DIR}/config.h"
)

set(Boost_USE_MULTITHREADED ON)

# find_package(Boost
#    1.60.0
#    REQUIRED
#    COMPONENTS system chrono date_time atomic thread
#)
#include_directories(${Boost_INCLUDE_DIRS})

# Projects
add_subdirectory(${PROJECT_SOURCE_DIR}/src/common/)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/assembler/)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/tinycom/)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/tinyide/)
