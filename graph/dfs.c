//
// Created by xhinliang on 16-3-16.
//
#include <stdlib.h>
#include <string.h>
#include "graph.h"
#include "dfs.h"

void dfs_exec(const Graph *graph, const int origin, Queue *queue, int *find) {
    // 标记找到的节点
    find[origin] = FIND;
    queue_enqueue(queue, origin);
    Graph_Edge *temp = graph->node[origin].first;
    while (temp) {
        if (find[temp->adj] == NOT_FIND) {
            dfs_exec(graph, temp->adj, queue, find);
        }
        temp = temp->next;
    }
}

Queue *dfs(const Graph *graph, const int origin) {
    Queue *queue = get_Queue();
    int *find = (int *) malloc(graph->size * sizeof(int));
    memset(find, NOT_FIND, (unsigned long) graph->size);
    dfs_exec(graph, origin, queue, find);
    free(find);
    return queue;
}
