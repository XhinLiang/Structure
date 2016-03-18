//
// Created by xhinliang on 16-3-14.
//
#include <stdio.h>
#include <stdlib.h>
#include "dijkstra.h"
#include "../util/queue.h"
#include "../util/common.h"
#include "bfs.h"
#include "floyd.h"

void test_dfs(const Graph *graph) {
    Queue *queue = bfs(graph, 0);
    int temp = queue_dequeue_int(queue);
    while (temp != EMPTY) {
        printf("%s ", graph->node[temp]);
        temp = queue_dequeue_int(queue);
    }
    free(queue);
}

void test_dijkstra(const Graph *graph, const int origin) {
    Dijkstra_Result *result;
    result = dijkstra(graph, origin);
    print_dijkstra_min_weight(result, graph);
    print_dijkstra_min_path(result, graph);
}

void test_floyd(const Graph *graph) {
    Floyd_Result *result = floyd(graph);
    print_floyd_result(graph, result);
    free(result);
}

int main() {
    freopen("data.in", "r", stdin);
    int temp;
    scanf("%d", &temp);
    Graph *graph = get_Graph(temp);

    test_floyd(graph);

    free(graph);
    fclose(stdin);
    return 0;
}

