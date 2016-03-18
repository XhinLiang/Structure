//
// Created by xhinliang on 16-3-18.
//

#include "graph.h"

#ifndef STRUCTURE_FLOYD_H
#define STRUCTURE_FLOYD_H

typedef struct {
    int **min_weight;
    int **min_path;
} Floyd_Result;


Floyd_Result *floyd(const Graph *graph);

void print_floyd_result(const Graph *graph, const Floyd_Result *result);

#endif //STRUCTURE_FLOYD_H
