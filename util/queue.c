//
// Created by xhinliang on 16-3-15.
//

#include "queue.h"
#include "common.h"

Queue *get_Queue() {
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    queue->node = NULL;
    return queue;
};

void *queue_dequeue(Queue *queue) {
    void *result = NULL;
    if (!queue->node)
        return NULL;
    result = queue->node->data;
    Queue_node *node = queue->node;
    queue->node = node->next;
    free(node);
    return result;
};

void queue_enqueue(Queue *queue, void *data) {
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

void queue_enqueue_int(Queue *queue, int data) {
    int *temp = (int *) malloc(sizeof(int));
    *temp = data;
    queue_enqueue(queue, temp);
}

int queue_dequeue_int(Queue *queue) {
    int *result = (int *) queue_dequeue(queue);
    return result ? *result : EMPTY;
}