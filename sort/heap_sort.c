//
// Created by xhinliang on 16-3-16.
//
#include "heap_sort.h"
#include "../util/common.h"
#include "../tree/array_tree.h"


/**
 * 在堆的最后添加一个元素，调整
 */
void heap_append(int *data, int index) {
    while (index > 0 && data[index] > data[get_parent(index)]) {
        swap(data + index, data + index / 2);
        index /= 2;
    }
}

void heap_fix(int *data, const int length) {
    int i, n = (length - 1) / 2;
    for (i = 0; i < n; ++i) {
        if (data[get_right(i)] > data[i] && data[get_left(i)] < data[get_right(i)]) {
            swap(data + get_right(i), data + i);
            continue;
        }
        if (data[get_left(i)] > data[i] && data[get_left(i)] > data[get_right(i)]) {
            swap(data + get_left(i), data + i);
        }
    }
}

void heap_sort(int *data, const int length) {
    int i;
    for (i = 1; i < length; ++i)
        heap_append(data, i);
    for (i = length - 1; i > 0;) {
        swap(data + i, data);
        heap_fix(data, i--);
    }
};

