cmake_minimum_required(VERSION 3.18)

project(graph)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O3")

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})
set(GRAPH_LIB_DIR        ${PROJECT_SOURCE_DIR}/lib)
set(GRAPH_INCLUDE_DIR    ${PROJECT_SOURCE_DIR}/include)

set(GRAPH_HEADERS_DIR    ${PROJECT_SOURCE_DIR}/graph)

include_directories(${GRAPH_INCLUDE_DIR})
include_directories(${GRAPH_HEADERS_DIR})

add_subdirectory(graph)
add_subdirectory(test)
