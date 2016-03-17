//
// Created by xhinliang on 16-3-14.
//
#include <stdio.h>
#include <stdlib.h>
#include "dijkstra.h"
#include "../util/queue.h"
#include "../util/common.h"
#include "bfs.h"

void test_dfs(const Graph *graph) {
    Queue *queue = bfs(graph, 0);
    int temp = queue_dequeue(queue);
    while (temp != EMPTY) {
        printf("%s ", graph->node[temp]);
        temp = queue_dequeue(queue);
    }
    free(queue);
}

int main() {
    freopen("data.in", "r", stdin);
    int temp;
    scanf("%d", &temp);
    Graph *graph = get_Graph(temp);

    test_dfs(graph);

    free(graph);
    fclose(stdin);
    return 0;
}

void test_dijkstra(const Graph *graph) {
    Result *result;
    result = dijkstra(graph, 0);
    print_min_weight(result, graph);
    print_min_path(result, graph);
}