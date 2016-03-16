#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "kmp.h"

int *make_next(const char *pattern) {
    int length = (int) strlen(pattern);
    int *next = (int *) malloc(length * sizeof(int));
    int q, k = 0;
    next[0] = 0;
    for (q = 1; q < length; ++q) {
        while (k > 0 && pattern[q] != pattern[k])
            k = next[k - 1];
        if (pattern[q] == pattern[k])
            ++k;
        next[q] = k;
    }
    return next;
}

/**
 * KMP
 * 字符串的快速匹配算法
 */
int kmp(const char *source, const char *pattern) {
    int source_length, pattern_length;
    int i = -1, q = 0;
    int *next;
    source_length = (int) strlen(source);
    pattern_length = (int) strlen(pattern);
    next = make_next(pattern);
    while (++i < source_length) {
        while (q > 0 && pattern[q] != source[i])
            q = next[q - 1];
        if (pattern[q] == source[i])
            ++q;
        if (q == pattern_length) {
            free(next);
            return i - pattern_length + 1;
        }
    }
    free(next);
    return NOT_FOUND;
}


