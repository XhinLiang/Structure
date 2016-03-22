//
// Created by xhinliang on 16-3-21.
//

/* 339
 * Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.
 *
 * Example:
 * For num = 5 you should return [0,1,1,2,1,2].
 *
 * Follow up:
 *
 *  - It is very easy to come up with a solution with run time O(n*sizeof(integer)).
 *  - But can you do it in linear time O(n) /possibly in a single pass?
 *  - Space complexity should be O(n).
 */

#include <stdlib.h>
#include <stdio.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *countBits(int num, int *returnSize) {
    int i;
    *returnSize = num + 1;
    int *result = (int *) malloc(*returnSize * sizeof(int));
    result[0] = 0;
    result[1] = result[2] = 1;
    int t = 4;
    int half_t = 2;
    for (i = 3; i <= num; ++i) {
        if (i == t) {
            result[i] = 1;
            half_t = t;
            t *= 2;
            continue;
        }
        result[i] = 1 + result[i % half_t];
    }
    return result;
}

int main() {
    int length;
    int *result;
    int i;
    result = countBits(8, &length);
    for (i = 0; i < length;)
        printf("%d ", result[i++]);
    free(result);
    return 0;
}
