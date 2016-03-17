//
// Created by xhinliang on 16-3-17.
//

#ifndef STRUCTURE_LINKED_TREE_H
#define STRUCTURE_LINKED_TREE_H

#define NAME_LENGTH 20

typedef struct Linked_Tree {
    struct Linked_Tree *left;
    struct Linked_Tree *right;
    char *name;
} Linked_Tree;

Linked_Tree *get_Linked_Tree();

#endif //STRUCTURE_LINKED_TREE_H
