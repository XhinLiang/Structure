/**
 * Graph
 **/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

int *get_visit_array(const Graph *graph) {
    int *visit = (int *) malloc(graph->size * sizeof(int));
    memset(visit, NOT_FIND, (unsigned long) graph->size);
    return visit;
}

Graph *get_Graph(const int length) {
    int i, j, edge_num_of_node;
    Graph_Edge *now;
    Graph *graph = (Graph *) malloc(sizeof(Graph));
    graph->size = length;
    graph->node = (Graph_Node *) malloc(length * sizeof(Graph_Node));
    for (i = 0; i < graph->size; ++i) {
        graph->node[i].name = (char *) malloc(NAME_LENGTH * sizeof(char));
        graph->node[i].first = (Graph_Edge *) malloc(sizeof(Graph_Edge));
        scanf("%s%d", graph->node[i].name, &edge_num_of_node);
        now = graph->node[i].first;
        if (!edge_num_of_node)
            continue;
        for (j = 1; j < edge_num_of_node; ++j) {
            scanf("%d%d", &(now->adj), &(now->weight));
            now->next = (Graph_Edge *) malloc(sizeof(Graph_Edge));
            now = now->next;
        }
        scanf("%d%d", &(now->adj), &(now->weight));
        now->next = NULL;
    }
    return graph;
}

