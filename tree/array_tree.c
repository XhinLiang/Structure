//
// Created by xhinliang on 16-3-16.
//
#include "array_tree.h"

int get_parent(int index) {
    return (index - 1) / 2;
}

int get_left(int index) {
    return 2 * index + 1;
}

int get_right(int index) {
    return 2 * index + 2;
}