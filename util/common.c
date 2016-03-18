//
// Created by xhinliang on 16-3-16.
//
#include <string.h>
#include "common.h"

void swap(int *a, int *b) {
    if (*a != *b) {
        *a ^= *b;
        *b ^= *a;
        *a ^= *b;
    }
}

int max(int a, int b) {
    return a > b ? a : b;
}

void str_copy(char *source, char *target) {
    int i;
    for (i = 0; source[i]; ++i) {
        target[i] = source[i];
    }
}
