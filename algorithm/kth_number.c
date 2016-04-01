//
// Created by xhinliang on 16-3-23.
//

/*
 * XX2016实习生招聘
 * 根据快速排序的算法，找出数组中第 k 大的数，k 从 0 开始数。
 */
#include <stdio.h>
#include <stdlib.h>

#define N 10000

int kth_number(int *array, const int length, const int k) {
    int stand = array[0];
    int start = 0;
    int end = length - 1;
    while (start < end) {
        while (start < end && array[end] < stand)
            --end;
        array[start] = array[end];
        if (start == end)
            break;
        while (start < end && array[start] > stand)
            ++start;
        array[end] = array[start];
    }
    array[start] = stand;
    // 这时候所在的这个部分已经排好序了，这也是这个算法的最坏情况
    if (length < 3)
        return array[k];
    if (start == k)
        return stand;
    if (k < start) {
        if (start < 2)
            return array[k];
        return kth_number(array, start, k);
    }
    // k > start
    if (length - start < 3)
        return array[k];
    return kth_number(array + start + 1, length - start - 1, k - start - 1);
}

int main() {
    int i, n, k;
    int *array = (int *) malloc(N * sizeof(int));
    scanf("%d%d", &n, &k);
    while (n > 0) {
        for (i = 0; i < n; ++i)
            scanf("%d", array + i);
        printf("%d\n", kth_number(array, n, k));
        scanf("%d%d", &n, &k);
    }
    free(array);
    return 0;
}