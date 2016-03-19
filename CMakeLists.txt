cmake_minimum_required(VERSION 2.8)
project(Structure)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c11")

set(GRAPH_FILES array/array.c array/array.h
        graph/graph.c graph/graph.h graph/dijkstra.c graph/dijkstra.h graph/main.c
        util/stack.c util/stack.h util/common.h util/queue.h util/queue.c
        graph/main.c array/kmp.h graph/dfs.h graph/dfs.c graph/bfs.c
        graph/bfs.h graph/floyd.h graph/floyd.c)

set(UTIL_FILES util/stack.c util/stack.h util/common.h
        util/queue.c util/queue.h util/main.c util/heap.h util/heap.c util/common.c
        tree/array_tree.c tree/array_tree.h)

set(ARRAY_FILES array/array.h array/array.c array/kmp.c array/kmp.h array/main.c
        graph/graph.h graph/graph.c util/common.c util/common.h
        array/binary_search.c array/binary_search.h)

set(SORT_FILES sort/main.c sort/quick_sort.h sort/quick_sort.c sort/merge_sort.h
        sort/merge_sort.c sort/insert_sort.h sort/insert_sort.c sort/select_sort.c sort/select_sort.h
        sort/shell_sort.c sort/shell_sort.h sort/heap_sort.h sort/heap_sort.c
        util/common.c util/common.h tree/array_tree.c tree/array_tree.h)


set(TREE_FILES util/common.h util/common.c util/queue.c util/stack.c
        tree/array_tree.c tree/array_tree.h tree/tree.c tree/tree.h
        tree/main.c)


add_executable(Graph ${GRAPH_FILES})

add_executable(Sort ${SORT_FILES})

add_executable(Util ${UTIL_FILES})

add_executable(Array ${ARRAY_FILES})

add_executable(Tree ${TREE_FILES})

add_executable(One_zero_pack algorithm/one_zero_pack.c util/common.c util/common.h)

add_executable(Prime_sieve algorithm/prime_sieve.c util/common.c util/common.h)
