#ifndef GRAPH_DIJKSTRA_H
#define GRAPH_DIJKSTRA_H

#include "graph.h"

typedef struct {
    int size;
    int original;
    int *min_weight;
    int *min_path;
} Dijkstra_Result;

void print_min_weight(const Dijkstra_Result *result, const Graph *graph);

void print_min_path(const Dijkstra_Result *result, const Graph *graph);

Dijkstra_Result *dijkstra(const Graph *graph, const int original);

#endif
