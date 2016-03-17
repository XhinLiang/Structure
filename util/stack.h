//
// Created by xhinliang on 16-3-15.
//

#ifndef GRAPH_STACK_H
#define GRAPH_STACK_H

#include <stdlib.h>


typedef struct Stack_node {
    void *data;
    struct Stack_node *next;
} Stack_node;

typedef struct {
    Stack_node *node;
} Stack;

Stack *get_Stack();

void *stack_pop(Stack *stack);

void stack_push(Stack *stack, void *data);

int stack_pop_int(Stack *stack);

void stack_push_int(Stack *stack, int data);

#endif //GRAPH_STACK_H
