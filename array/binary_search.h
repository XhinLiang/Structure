//
// Created by xhinliang on 16-3-18.
//

#ifndef STRUCTURE_BINARY_SEARCH_H
#define STRUCTURE_BINARY_SEARCH_H


int binary_search(const void *source, const int length, const void *des,
                  int (*compare)(const void *, const int, const void *));

#endif //STRUCTURE_BINARY_SEARCH_H
