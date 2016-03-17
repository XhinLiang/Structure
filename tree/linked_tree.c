//
// Created by xhinliang on 16-3-17.
//

#include <stdlib.h>
#include <stdio.h>
#include "linked_tree.h"
#include "../util/queue.h"
#include "../util/common.h"

char *get_name_string() {
    return (char *) malloc(NAME_LENGTH * sizeof(char));
}

Linked_Tree *new_node() {
    Linked_Tree *node = (Linked_Tree *) malloc(sizeof(Linked_Tree));
    node->name = get_name_string();
    node->left = NULL;
    node->right = NULL;
    return node;
}

Linked_Tree *get_Linked_Tree() {
    char *name = get_name_string();
    Linked_Tree *now, *temp;
    Queue *queue = get_Queue();
    Linked_Tree *root = new_node();
    printf("root\n");
    scanf("%s", root->name);
    queue_enqueue(queue, root);
    now = (Linked_Tree *) queue_dequeue(queue);
    while (now) {
        printf("%s left\n", now->name);
        scanf("%s", name);
        if (name[0] != '#') {
            temp = new_node();
            str_copy(name, temp->name);
            now->left = temp;
            queue_enqueue(queue, temp);
        }
        printf("%s right\n", now->name);
        scanf("%s", name);
        if (name[0] != '#') {
            temp = new_node();
            str_copy(name, temp->name);
            now->right = temp;
            queue_enqueue(queue, temp);
        }
        now = queue_dequeue(queue);
    }
    return root;
}

