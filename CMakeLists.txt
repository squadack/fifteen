cmake_minimum_required (VERSION 2.8)

project (fifteen)

set (EXECUTABLE_OUTPUT_PATH "${fifteen_BINARY_DIR}/bin")
set (CMAKE_CXX_FLAGS "-std=c++11")

find_package (Qt4 REQUIRED)
include (${QT_USE_FILE})
add_definitions (${QT_DEFINITIONS})

add_subdirectory (src)

