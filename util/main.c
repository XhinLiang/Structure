//
// Created by xhinliang on 16-3-15.
//

#include <stdio.h>
#include "queue.h"
#include "stack.h"
#include "common.h"

int main() {
    int i;
    Stack *stack = get_Stack();
    Queue *queue = get_Queue();
    for (i = 0; i < 10; ++i) {
        push(stack, i);
        enqueue(queue, i);
    }

    i = pop(stack);
    while (i != EMPTY) {
        printf("%d ", i);
        i = pop(stack);
    }
    free(stack);
    printf("\n");

    i = dequeue(queue);
    while (i != EMPTY) {
        printf("%d ", i);
        i = dequeue(queue);
    }
    free(queue);
    printf("\n");

    return 0;
}