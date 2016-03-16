//
// Created by xhinliang on 16-3-15.
//

#include "queue.h"
#include "common.h"

Queue *get_Queue() {
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    queue->node = NULL;
};

int queue_dequeue(Queue *queue) {
    int result;
    if (!queue->node)
        return EMPTY;
    result = queue->node->data;
    Queue_node *node = queue->node;
    queue->node = node->next;
    free(node);
    return result;
};

void queue_enqueue(Queue *queue, int data) {
    Queue_node *en_node = (Queue_node *) malloc(sizeof(Queue_node));
    en_node->data = data;
    en_node->next = NULL;
    if (!queue->node) {
        queue->node = en_node;
        return;
    }
    Queue_node *node = queue->node;
    while (node->next) {
        node = node->next;
    }
    node->next = en_node;
};