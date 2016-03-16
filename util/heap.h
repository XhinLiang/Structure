//
// Created by xhinliang on 16-3-15.
//

#ifndef STRUCTURE_HEAP_H
#define STRUCTURE_HEAP_H

typedef enum {
    HEAP_MIN, HEAP_MAX
} Type;

typedef struct {
    Type type;
    int *data;
    int length, max_length;
} Heap;

void heap_insert(Heap *heap, const int insert_data);

void heap_fix_insert(Heap *heap);

Heap *get_max_Heap(const int max_length);

Heap *get_min_Heap(const int max_length);

#endif //STRUCTURE_HEAP_H
