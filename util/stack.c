//
// Created by xhinliang on 16-3-15.
//

#include "stack.h"
#include "common.h"

Stack *get_Stack() {
    Stack *stack = (Stack *) malloc(sizeof(Stack));
    stack->node = NULL;
    return stack;
}

int pop(Stack *stack) {
    int result;
    Stack_node *now = stack->node;
    Stack_node *forward = now;
    if (!now)
        return EMPTY;
    while (now->next) {
        forward = now;
        now = now->next;
    }
    result = now->data;
    free(now);
    if (forward != now)
        forward->next = NULL;
    else
        stack->node = NULL;
    return result;
}

void push(Stack *stack, int data) {
    Stack_node *push_node = (Stack_node *) malloc(sizeof(Stack_node));
    push_node->data = data;;
    push_node->next = NULL;
    Stack_node *now = stack->node;
    if (!now) {
        stack->node = push_node;
        return;
    }
    while (now->next) {
        now = now->next;
    }
    now->next = push_node;
}