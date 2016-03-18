//
// Created by xhinliang on 16-3-16.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kmp.h"
#include "../graph/graph.h"
#include "binary_search.h"
#include "../util/common.h"

void test_kmp() {
    char source[] = "pattepattepatternpapatternpatee";
    char pattern1[] = "pattern";
    char pattern2[] = "patternpat";
    int i, j;
    for (i = 0; i < 4; ++i)
        for (j = 0; j < 10; ++j)
            printf("%d", i);
    puts("");
    for (i = 0; i < 4; ++i)
        for (j = 0; j < 10; ++j)
            printf("%d", j);
    puts("");
    printf("%s %s %d \n", source, pattern1, kmp(source, pattern1));
    printf("%s %s %d \n", source, pattern2, kmp(source, pattern2));
}

int compare(const void *a, const int index, const void *b) {
    int A = *((int *) a + index);
    int B = *((int *) b);
    if (A == B)
        return EQUAL;
    if (A < B)
        return LARGE;
    return SMALL;
}

int main() {
    int t = 34;
    int array[] = {1, 4, 5, 6, 8, 10, 34, 43};
    int temp = binary_search(array, 8, &t, compare);
    printf("%d", temp);
    return 0;
}

