//
// Created by xhinliang on 16-3-18.
//

#include <stdlib.h>
#include <stdio.h>
#include "floyd.h"
#include "../array/array.h"
#include "../util/stack.h"
#include "../util/common.h"

Floyd_Result *floyd(const Graph *graph) {
    int i, j, k;
    Floyd_Result *result = (Floyd_Result *) malloc(sizeof(Floyd_Result));
    result->min_path = get_int_array(graph->size, graph->size);
    result->min_weight = get_int_array(graph->size, graph->size);

    for (i = 0; i < graph->size; ++i) {
        for (j = 0; j < graph->size; ++j) {
            if (i == j) {
                result->min_path[i][j] = i;
                result->min_weight[i][j] = 0;
                continue;
            }
            result->min_weight[i][j] = MAX;
            result->min_path[i][j] = NOT_FIND;
        }
    }

    Graph_Edge *temp;
    for (i = 0; i < graph->size; ++i) {
        temp = graph->node[i].first;
        while (temp) {
            result->min_path[i][temp->adj] = i;
            result->min_weight[i][temp->adj] = temp->weight;
            temp = temp->next;
        }
    }

    for (k = 0; k < graph->size; ++k) {
        for (i = 0; i < graph->size; ++i) {
            for (j = 0; j < graph->size; ++j) {
                if (j == k || j == i || k == i)
                    continue;
                if (result->min_weight[i][j] > result->min_weight[i][k] + result->min_weight[k][j]) {
                    result->min_weight[i][j] = result->min_weight[i][k] + result->min_weight[k][j];
                    result->min_path[i][j] = k;
                }
            }
        }
    }

    return result;
}


void print_floyd_result(const Graph *graph, const Floyd_Result *result) {
    int i, j;
    int temp;
    Stack *stack = get_Stack();

    for (i = 0; i < graph->size; ++i) {
        for (j = 0; j < graph->size; ++j) {
            printf("%d  ", result->min_weight[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < graph->size; ++i) {
        for (j = 0; j < graph->size; ++j) {
            if (i == j)
                continue;
            printf("\n");
            if (result->min_path[i][j] == NOT_FIND) {
                printf("No path from %s to %s\n", graph->node[i].name, graph->node[j].name);
                continue;
            }
            stack_push_int(stack, j);
            temp = result->min_path[i][j];
            while (temp != i) {
                stack_push_int(stack, temp);
                temp = result->min_path[i][temp];
            }
            stack_push_int(stack, i);

            temp = stack_pop_int(stack);
            while (temp != EMPTY) {
                printf("%s ", graph->node[temp].name);
                temp = stack_pop_int(stack);
            }

            printf("%d", result->min_weight[i][j]);
        }
    }
}