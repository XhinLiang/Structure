//
// Created by xhinliang on 16-3-15.
//

#ifndef GRAPH_STACK_H
#define GRAPH_STACK_H

#include <stdlib.h>



typedef struct Stack_node {
    int data;
    struct Stack_node *next;
} Stack_node;

typedef struct {
    Stack_node *node;
} Stack;

Stack *get_Stack();

int stack_pop(Stack *stack);

void stack_push(Stack *stack, int data);

#endif //GRAPH_STACK_H
