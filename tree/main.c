//
// Created by xhinliang on 16-3-17.
//
#include <stdio.h>
#include "tree.h"

void print_queue(Queue *queue);

int main() {
    freopen("data.in", "r", stdin);

    Tree *tree = get_Tree();
    Queue *queue;
    queue = pre_order(tree);
    print_queue(queue);
    queue = mid_order(tree);
    print_queue(queue);
    queue = pos_order(tree);
    print_queue(queue);

    fclose(stdin);
    return 0;
}

void print_queue(Queue *queue) {
    Tree *temp = (Tree *) queue_dequeue(queue);
    while (temp) {
        printf("%s ", temp->name);
        temp = (Tree *) queue_dequeue(queue);
    }
    puts("");
    free(queue);
}