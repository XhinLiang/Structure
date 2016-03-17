//
// Created by xhinliang on 16-3-17.
//
#include "bfs.h"
#include "../util/common.h"

Queue *bfs(const Graph *graph, const int origin) {
    int *visit = get_visit_array(graph);
    int temp = origin;
    Graph_Edge *edge;
    Queue *find = get_Queue();
    Queue *handle = get_Queue();
    visit[temp] = FIND;
    queue_enqueue_int(find, temp);
    while (temp != EMPTY) {
        edge = graph->node[temp].first;
        while (edge) {
            if (visit[edge->adj] == FIND) {
                edge = edge->next;
                continue;
            }
            visit[edge->adj] = FIND;
            queue_enqueue_int(handle, edge->adj);
            queue_enqueue_int(find, edge->adj);
            edge = edge->next;
        }
        temp = queue_dequeue_int(handle);
    }
    free(handle);
    free(visit);
    return find;
}
