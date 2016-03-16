//
// Created by xhinliang on 16-3-16.
//

#include <stdio.h>
#include "kmp.h"

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

int main() {
    test_kmp();
}

