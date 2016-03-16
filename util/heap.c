//
// Created by xhinliang on 16-3-15.
//

#include <stdlib.h>
#include "heap.h"
#include "common.h"
#include "../tree/tree.h"

/**
 * 获得一个最大长度为 max_length 的二叉堆，未指定最大或者最小
 */
Heap *get_Heap(const int max_length) {
    Heap *heap = (Heap *) malloc(sizeof(Heap));
    heap->length = 0;
    heap->max_length = max_length;
    heap->data = (int *) malloc(max_length * sizeof(int));
    return heap;
}

/**
 * 每次插入元素都要进行堆的调整
 */
void heap_fix_insert(Heap *heap) {
    int i = heap->length - 1;
    // 最大堆的情况
    while (heap->type == HEAP_MAX && i > 0 && heap->data[i] > heap->data[get_parent(i)]) {
        swap(heap->data + i, heap->data + get_parent(i));
        i = get_parent(i);
    }
    // 最小堆的情况
    while (heap->type == HEAP_MIN && i > 0 && heap->data[i] < heap->data[get_parent(i)]) {
        swap(heap->data + i, heap->data + get_parent(i));
        i = get_parent(i);
    }
}

/**
 * 在最尾插入一个元素，然后重建堆
 */
void heap_insert(Heap *heap, const int insert_data) {
    if (heap->length == heap->max_length)
        return;
    if (!heap->length) {
        heap->data[heap->length++] = insert_data;
        return;
    }
    heap->data[heap->length++] = insert_data;
    heap_fix_insert(heap);
}


Heap *get_max_Heap(const int max_length) {
    Heap *heap = get_Heap(max_length);
    heap->type = HEAP_MAX;
    return heap;
}

Heap *get_min_Heap(const int max_length) {
    Heap *heap = get_Heap(max_length);
    heap->type = HEAP_MIN;
    return heap;
}

