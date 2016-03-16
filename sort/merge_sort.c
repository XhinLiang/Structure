//
// Created by xhinliang on 16-3-15.
//
#include <stdlib.h>

/**
 * 两个有序的数组合并成为另一个大的有序数组
 */
void merge(int *data_a, const int length_a, const int length_b) {
    int i = 0, j = 0, k = 0;
    int *data_b = data_a + length_a;
    int *merge_data = (int *) malloc((length_a + length_b) * sizeof(int));
    while (i < length_a && j < length_b) {
        if (data_a[i] < data_b[j]) {
            merge_data[k++] = data_a[i++];
            continue;
        }
        merge_data[k++] = data_b[j++];
    }
    while (j < length_b)
        merge_data[k++] = data_b[j++];
    while (i < length_a)
        merge_data[k++] = data_a[i++];
    for (i = 0; i < k; ++i) {
        data_a[i] = merge_data[i];
    }
}

/**
 * 归并排序
 */
void merge_sort(int *data, const int length) {
    int middle = length / 2;
    if (length > 1) {
        merge_sort(data, middle);
        merge_sort(data + middle, length - middle);
        merge(data, middle, length - middle);
    }
}

