//
// Created by xhinliang on 16-3-15.
//

#ifndef GRAPH_QUEUE_H
#define GRAPH_QUEUE_H

#include <stdlib.h>


typedef struct Queue_node {
    int data;
    struct Queue_node *next;
} Queue_node;

typedef struct {
    Queue_node *node;
} Queue;

Queue *get_Queue();

int dequeue(Queue *queue);

void enqueue(Queue *queue, int data);

#endif //GRAPH_QUEUE_H
