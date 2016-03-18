//
// Created by xhinliang on 16-3-17.
//

#include "../util/queue.h"

#ifndef STRUCTURE_LINKED_TREE_H
#define STRUCTURE_LINKED_TREE_H

#define NAME_LENGTH 20

typedef struct Tree {
    struct Tree *left;
    struct Tree *right;
    char name[NAME_LENGTH];
} Tree;

Tree *get_Tree();

Queue *pre_order(Tree *tree);

Queue *mid_order(Tree *tree);

Queue *pos_order(Tree *tree);

#endif //STRUCTURE_LINKED_TREE_H
