//
// Created by xhinliang on 16-3-15.
//
#include <stdio.h>
#include "queue.h"
#include "stack.h"
#include "common.h"
#include "heap.h"

void stack_queue();

void heap();

int main() {
    heap();
    return 0;
}

void heap() {
    int i;
    int data[] = {23, 21, 55, 32, 66, 77, 33};
    Heap *heap = get_max_Heap(100);
    for (i = 0; i < 7; ++i) {
        heap_insert(heap, data[i]);
    }

    for (i = 0; i < 7; ++i) {
        printf("%d ", heap->data[i]);
    }
}

void stack_queue() {
    int i;
    Stack *stack = get_Stack();
    Queue *queue = get_Queue();
    for (i = 0; i < 10; ++i) {
        stack_push(stack, i);
        queue_enqueue(queue, i);

    }

    i = stack_pop(stack);
    while (i != EMPTY) {
        printf("%d ", i);
        i = stack_pop(stack);
    }
    free(stack);
    printf("\n");

    i = queue_dequeue(queue);
    while (i != EMPTY) {
        printf("%d ", i);
        i = queue_dequeue(queue);
    }
    free(queue);
    printf("\n");
}