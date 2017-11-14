//
// Created by xhinliang on 17-11-14.
//
#include <string.h>
#include "tree.h"

/**
 * 0 => 相等 1 => (a > b) -1 => (a < b)
 */
int compare(Tree *a, Tree *b) {
    return strcmp(a->name, b->name);
}

void merge_node_to_tree(Tree *tree_a, Tree *node) {
    if (tree_a == NULL || node == NULL) {
        return;
    }

    // 相等不插
    if (compare(tree_a, node) == 0) {
        return;
    }

    // node 大于当前树根，插到右边
    if (compare(tree_a, node) == -1) {
        if (tree_a->right != NULL) {
            merge_node_to_tree(tree_a, node);
        } else {
            tree_a->right = node;
        }
        return;
    }

    // node 小于当前树根，插到左边
    if (compare(tree_a, node) == 1) {
        if (tree_a->left != NULL) {
            merge_node_to_tree(tree_a->left, node);
        } else {
            tree_a->left = node;
        }
        return;
    }
}

void merge_binary_tree(Tree *tree_a, Tree *tree_b) {
    if (tree_b == NULL || tree_a == NULL) {
        return;
    }

    if (tree_b->left != NULL) {
        merge_binary_tree(tree_a, tree_b->left);
    }

    if (tree_b->right != NULL) {
        merge_binary_tree(tree_a, tree_b->right);
    }

    merge_node_to_tree(tree_a, tree_b);
}

