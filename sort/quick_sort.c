#include "quick_sort.h"

/**
 * 快速排序
 */
void quick_sort(int *data, const int length) {
    if (length < 2)
        return;
    int start = 0, end = length - 1;
    int stand = data[0];
    while (start < end) {
        while (data[end] > stand && start < end) {
            --end;
        }
        if (start == end)
            break;
        data[start] = data[end];
        while (data[start] < stand && start < end) {
            ++start;
        }
        data[end] = data[start];
    }
    data[start] = stand;
    quick_sort(data, start);
    quick_sort(data + start + 1, length - start - 1);
}

