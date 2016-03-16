//
// Created by xhinliang on 16-3-15.
//
#include "shell_sort.h"
#include "insert_sort.h"

/**
 * 希尔排序，事实上就是分小块的直接插入排序
 */
void shell_sort(int *data, const int length) {
    int middle;
    if (length > 2) {
        middle = length / 2;
        shell_sort(data, middle);
        shell_sort(data + middle, length - middle);
    }
    insert_sort(data,length);
}
