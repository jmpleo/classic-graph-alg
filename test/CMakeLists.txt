cmake_minimum_required(VERSION 3.18)

project(graph-tests)

add_subdirectory(lib/googletest)

include_directories(${GRAPH_HEADERS_DIR})
include_directories(lib/googletest/googletest/include)

set(SOURCE_FILES main.cpp
                 src/graph-tests.cpp)

add_executable(graph-tests ${SOURCE_FILES})
target_link_libraries(graph-tests graph gtest)
install(TARGETS graph-tests DESTINATION bin)
