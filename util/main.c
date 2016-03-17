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
    stack_queue();
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
    int *temp;
    Stack *stack = get_Stack();
    Queue *queue = get_Queue();
    for (i = 0; i < 10; ++i) {
        temp = (int *) malloc(sizeof(int));
        *temp = i;
        stack_push(stack, temp);
        queue_enqueue(queue, temp);

    }

    temp = (int *) stack_pop(stack);
    while (temp != EMPTY) {
        printf("%d ", *temp);
        temp = (int *) stack_pop(stack);
    }
    free(stack);
    printf("\n");

    temp = (int *) queue_dequeue(queue);
    while (temp != EMPTY) {
        printf("%d ", *temp);
        temp = (int *) queue_dequeue(queue);
    }
    free(queue);
    printf("\n");
}