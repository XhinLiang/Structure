//
// Created by xhinliang on 16-3-18.
//

#include "../util/common.h"

int binary_search_exec(const void *source, const int start, const int end, const void *des,
                       int (*compare)(const void *, const int, const void *)) {
    int length = end - start + 1;
    int half = length / 2;
    int compare_result = compare(source, start + half, des);
    if (compare_result == EQUAL)
        return half;
    if (compare_result == SMALL)
        return binary_search_exec(source, 0, half, des, compare);
    return half + 1 + binary_search_exec(source, half + 1, end, des, compare);
}

int binary_search(const void *source, const int length, const void *des,
                  int (*compare)(const void *, const int, const void *)) {
    return binary_search_exec(source, 0, length - 1, des, compare);
}