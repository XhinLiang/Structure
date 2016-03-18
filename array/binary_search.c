//
// Created by xhinliang on 16-3-18.
//

#include "binary_search.h"

int binary_search_exec(const void *source, int start, int end, const void *des,
                       int (*compare)(const void *, const int, const void *)) {
    int length, half, compare_result;
    while (1) {
        length = end - start + 1;
        half = length / 2;
        compare_result = compare(source, start + half, des);
        if (compare_result == EQUAL)
            return start + half;
        if (length == 1)
            return NOT_FIND;
        if (length == 2 && compare(source, start, des) == EQUAL)
            return start;
        if (compare_result == SMALL) {
            end = start + half;
            continue;
        }
        if (compare_result == LARGE)
            start += half + 1;
    }
}


int binary_search(const void *source, const int length, const void *des,
                  int (*compare)(const void *, const int, const void *)) {
    return binary_search_exec(source, 0, length - 1, des, compare);
}