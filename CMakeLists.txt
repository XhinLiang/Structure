cmake_minimum_required(VERSION 2.8)
project(Structure)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c11")

set(GRAPH_FILES array/array.c array/array.h
        graph/graph.c graph/graph.h graph/dijkstra.c graph/dijkstra.h graph/main.c
        util/stack.c util/stack.h util/common.h
        graph/main.c tree/tree.c array/kmp.h)

set(UTIL_FILES util/stack.c util/stack.h util/common.h
        util/queue.c util/queue.h util/main.c util/heap.h util/heap.c util/common.c
        tree/tree.c tree/tree.h)

set(ARRAY_FILES array/array.h array/array.c array/kmp.c array/kmp.h array/main.c)

set(SORT_FILES sort/main.c sort/quick_sort.h sort/quick_sort.c sort/merge_sort.h
        sort/merge_sort.c sort/insert_sort.h sort/insert_sort.c sort/select_sort.c sort/select_sort.h
        sort/shell_sort.c sort/shell_sort.h sort/heap_sort.h sort/heap_sort.c
        util/common.c util/common.h tree/tree.c tree/tree.h)

add_executable(exec/Graph ${GRAPH_FILES})

add_executable(exec/Sort ${SORT_FILES})

add_executable(exec/Util ${UTIL_FILES})

add_executable(exec/Array ${ARRAY_FILES})
