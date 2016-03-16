//
// Created by xhinliang on 16-3-15.
//
#include "insert_sort.h"

/**
 * 直接插入排序
 */
void insert_sort(int *data, int length) {
    int i, j, k, temp;
    for (i = 1; i < length; ++i) {
        temp = data[i];
        // data[j] 是有序数组里比要插入的数据（data[i]）大的数据中最小的一个
        for (j = 0; data[j] < data[i]; ++j);
        // 将从 j 到 i 的这段数据向后移动
        for (k = i; k > j;) {
            data[k] = data[--k];
        }
        data[j] = temp;
    }
}

