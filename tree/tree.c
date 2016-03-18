//
// Created by xhinliang on 16-3-17.
//

#include <stdlib.h>
#include <stdio.h>
#include "tree.h"
#include "../util/common.h"


Tree *new_node() {
    Tree *node = (Tree *) malloc(sizeof(Tree));
    node->left = NULL;
    node->right = NULL;
    return node;
}

Tree *get_Tree() {
    char name[NAME_LENGTH];
    Tree *now, *temp;
    Queue *queue = get_Queue();
    Tree *root = new_node();
    printf("root\n");
    scanf("%s", root->name);
    queue_enqueue(queue, root);
    now = (Tree *) queue_dequeue(queue);
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

void pre_order_exec(Tree *tree, Queue *queue) {
    queue_enqueue(queue, tree);
    if (tree->left)
        pre_order_exec(tree->left, queue);
    if (tree->right)
        pre_order_exec(tree->right, queue);
}

/**
 * 前序遍历
 */
Queue *pre_order(Tree *tree) {
    Queue *queue = get_Queue();
    pre_order_exec(tree, queue);
    return queue;
}

void mid_order_exec(Tree *tree, Queue *queue) {
    if (tree->left)
        mid_order_exec(tree->left, queue);
    queue_enqueue(queue, tree);
    if (tree->right)
        mid_order_exec(tree->right, queue);
}

/**
 * 中序遍历
 */
Queue *mid_order(Tree *tree) {
    Queue *queue = get_Queue();
    mid_order_exec(tree, queue);
    return queue;
}

void pos_order_exec(Tree *tree, Queue *queue) {
    queue_enqueue(queue, tree);
    if (tree->left)
        pos_order_exec(tree->left, queue);
    if (tree->right)
        pos_order_exec(tree->right, queue);
}

/**
 * 后序遍历
 */
Queue *pos_order(Tree *tree) {
    Queue *queue = get_Queue();
    pos_order_exec(tree, queue);
    return queue;
}

