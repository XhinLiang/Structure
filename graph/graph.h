#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H

#define NAME_LENGTH 20

typedef struct Graph_Edge {
    int weight;
    int adj;
    struct Graph_Edge * next;
} Graph_Edge;

typedef struct {
    char* name;
    Graph_Edge * first;
} Node;

typedef struct {
    Node* node;
    int size;
} Graph;

Graph* get_Graph(const int node_sum);

#endif
