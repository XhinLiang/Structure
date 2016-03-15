//
// Created by xhinliang on 16-3-14.
//
#include <stdio.h>
#include "dijkstra.h"

int main() {
    freopen("data.in", "r", stdin);
    int temp;
    Result *result;
    scanf("%d", &temp);
    Graph *graph = get_Graph(temp);

    result = dijkstra(graph, 0);
    print_min_weight(result, graph);
    print_min_path(result, graph);

    fclose(stdin);
    return 0;
}