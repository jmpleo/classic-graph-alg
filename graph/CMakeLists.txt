cmake_minimum_required(VERSION 3.18)
project(graph)

set(SOURCE_FILES
    graph-alg.cpp
    graph-presented.cpp
    )

set(HEADER_FILES
    graph.h
    graph-alg.h
    graph-presented.h
    )

add_library(graph SHARED STATIC ${SOURCE_FILES})

install(TARGETS     graph
    DESTINATION ${GRAPH_LIB_DIR})

install(FILES       ${GRAPH_HEADER_FILES}
    DESTINATION ${GRAPH_INLCUDE_DIR})
