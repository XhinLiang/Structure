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

void *stack_pop(Stack *stack) {
    void *result = NULL;
    Stack_node *now = stack->node;
    Stack_node *forward = now;
    if (!now)
        return NULL;
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

void stack_push(Stack *stack, void *data) {
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

int stack_pop_int(Stack *stack) {
    int *result = (int *) stack_pop(stack);
    return result ? *result : EMPTY;
}

void stack_push_int(Stack *stack, int data) {
    int *temp = (int *) malloc(sizeof(int));
    *temp = data;
    stack_push(stack, temp);
}