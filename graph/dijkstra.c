#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"
#include "dijkstra.h"
#include "../array/array.h"
#include "../util/stack.h"
#include "../util/common.h"


Dijkstra_Result *dijkstra(const Graph *graph, const int original) {
    const int MAX = 0xfffffff;
    const int NOT_FOUND = -1;
    const int FOUND = 1;

    // 这点的最短路径前趋
    int *min_path;
    // 点到点的距离
    int **min_weight;

    min_weight = getIntArray(graph->size, graph->size);
    min_path = (int *) malloc(graph->size * sizeof(int));

    int i, j;
    for (i = 0; i < graph->size; ++i) {
        for (j = 0; j < graph->size; ++j) {
            if (i == j) {
                min_weight[i][j] = 0;
                continue;
            }
            min_weight[i][j] = MAX;
        }
    }

    Graph_Edge *edge;
    for (i = 0; i < graph->size; ++i) {
        edge = graph->node[i].first;
        while (edge) {
            min_weight[i][edge->adj] = edge->weight;
            min_path[edge->adj] = original;
            edge = edge->next;
        }
    }


    // find 数组记录已经找到最短路径的点
    int *find;
    find = (int *) malloc(graph->size * sizeof(int));
    memset(find, NOT_FOUND, (unsigned long) graph->size);
    // 首先自己肯定已经找到了最短路径
    find[original] = FOUND;


    int min_index, min;
    for (j = 1; j < graph->size; ++j) {
        // 找出原点中最短的一条边
        min_index = NOT_FOUND;
        min = MAX;
        for (i = 0; i < graph->size; ++i) {
            if (find[i] != FOUND && min_weight[original][i] < min) {
                min = min_weight[original][i];
                min_index = i;
            }
        }
        // 如果这个点已经被标记过，那么证明所有的点都处理过
        if (find[min_index] == FOUND)
            break;
        // 标记这个点
        find[min_index] = FOUND;
        // 以这个点为中间点，更新最短路程和最短路径前趋
        for (i = 0; i < graph->size; ++i) {
            if (find[i] == FOUND)
                continue;
            if (min_weight[original][min_index] + min_weight[min_index][i] < min_weight[original][i]) {
                min_weight[original][i] = min_weight[original][min_index] + min_weight[min_index][i];
                min_path[i] = min_index;
            }
        }
    }
    for (i = 0; i < graph->size; ++i) {
        if (i != original)
            free(min_weight[i]);
    }

    Dijkstra_Result *result;
    result = (Dijkstra_Result *) malloc(sizeof(Dijkstra_Result));
    result->original = original;
    result->min_path = min_path;
    result->min_weight = min_weight[original];
    result->size = graph->size;
    return result;
}


void print_min_weight(const Dijkstra_Result *result, const Graph *graph) {
    int i;
    for (i = 0; i < result->size; ++i) {
        printf("%s %s %d \n", graph->node[result->original].name, graph->node[i].name, result->min_weight[i]);
    }
}

void print_min_path(const Dijkstra_Result *result, const Graph *graph) {
    int i, temp;
    Stack *stack = get_Stack();
    for (i = 0; i < graph->size; ++i) {
        if (i != result->original)
            stack_push_int(stack, i);
        temp = result->min_path[i];
        stack_push_int(stack, temp);
        while (temp != result->original) {
            temp = result->min_path[temp];
            stack_push_int(stack, temp);
        }
        temp = stack_pop_int(stack);
        while (temp != EMPTY) {
            printf("%s ", graph->node[temp].name);
            temp = stack_pop_int(stack);
        }
        printf("\n");
    }
    free(stack);
}
