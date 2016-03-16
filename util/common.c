//
// Created by xhinliang on 16-3-16.
//
#include "common.h"

void swap(int *a, int *b) {
    if (*a != *b) {
        *a ^= *b;
        *b ^= *a;
        *a ^= *b;
    }
}