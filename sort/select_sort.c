//
// Created by xhinliang on 16-3-15.
//
#include "select_sort.h"

/**
 * 直接选择排序
 */
void select_sort(int *data, const int length) {
    // 只需要 length - 1 次循环，最后一位数不需要插
    const int n = length - 1;

    int i, j;
    int min_index, min;
    for (i = 0; i < n; ++i) {
        min = data[i];
        min_index = i;
        for (j = i + 1; j < length; ++j) {
            if (min > data[j]) {
                min = data[j];
                min_index = j;
            }
        }
        data[min_index] = data[i];
        data[i] = min;
    }
}
