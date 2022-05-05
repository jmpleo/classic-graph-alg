cmake_minimum_required(VERSION 3.18)

project(graph-tests)

add_subdirectory(lib/googletest)

include_directories(${GRAPH_HEADERS_DIR})
include_directories(lib/googletest/googletest/include)
SET(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
SET(CMAKE_C_FLAGS "-g -O0 -Wall -W -fprofile-arcs -ftest-coverage")
SET(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")

set(SOURCE_FILES main.cpp
                 src/graph-tests.cpp)

add_executable(graph-tests ${SOURCE_FILES})
target_link_libraries(graph-tests graph gtest)
install(TARGETS graph-tests DESTINATION bin)
