#ifndef GRAPH_DIJKSTRA_H
#define GRAPH_DIJKSTRA_H

#include "graph.h"

typedef struct {
    int size;
    int original;
    int *min_weight;
    int *min_path;
} Result;

void print_min_weight(const Result *result, const Graph *graph);

void print_min_path(const Result *result, const Graph *graph);

Result *dijkstra(const Graph *graph, const int original);

#endif
