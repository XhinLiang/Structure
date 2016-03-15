cmake_minimum_required(VERSION 3.3)
project(Structure)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c11")

set(GRAPH_FILES array/array.c array/array.h
        graph/graph.c graph/graph.h graph/dijkstra.c graph/dijkstra.h graph/main.c
        util/stack.c util/stack.h util/common.h util/main.c)

set(UTIL_FILES array/array.c array/array.h
        util/stack.c util/stack.h util/common.h util/queue.c util/queue.h util/main.c)

add_executable(Graph ${GRAPH_FILES})

add_executable(Util ${UTIL_FILES})