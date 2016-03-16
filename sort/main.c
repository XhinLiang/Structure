#include <stdio.h>
#include "merge_sort.h"
#include "insert_sort.h"
#include "select_sort.h"
#include "shell_sort.h"
#include "heap_sort.h"

//
// Created by xhinliang on 16-3-15.
//

int main() {
    int i ;
    int data[] = {33, 32, 39, 30, 22, 11, 44};
    heap_sort(data, 7);
    for (i = 0; i < 7; ++i) {
        printf("%d ", data[i]);
    }
    return 0;
}
