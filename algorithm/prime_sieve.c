//
// Created by xhinliang on 16-3-19.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../util/common.h"

typedef struct {
    int length;
    int *data;
} Prime_Result;


/**
 * 欧拉筛法求素数
 */
Prime_Result *prime_Euler(const int length) {
    int i, j;
    Prime_Result *result = NULL;
    // 假设所有的数都是素数
    // 这里需要进行预处理，所以需要 local static 变量
    static int *not_prime = NULL;
    static int *prime = NULL;
    static int prime_sum = -1;
    // 已经求出过的最大 length
    static int max_length = 0;

    if (!length) {
        // 输入长度为零的时候，释放内存
        free(not_prime);
        free(prime);
        prime = not_prime = NULL;
    }

    result = (Prime_Result *) malloc(sizeof(Prime_Result));
    result->data = (int *) malloc(length * sizeof(int));
    // 如果需要的长度正好是求出来的最大长度，直接赋值返回即可
    if (length == max_length) {
        int_array_copy(prime, result->data, length);
        result->length = prime_sum;
        return result;
    }
    // 如果需要的长度大于已经求出过的，需要重新分配内存，重新计算
    if (length > max_length) {
        max_length = length;

        // TODO 这个 free 会出错
        // free(): invalid pointer:
        if (prime) {
            free(prime);
            prime = NULL;
        }
        if (not_prime) {
            free(not_prime);
            not_prime = NULL;
        }

        not_prime = (int *) malloc(length * sizeof(int));
        prime = (int *) malloc(length * sizeof(int));


        // 初始化为每个都不不是素数（双重否定句）
        memset(not_prime, 0, sizeof(not_prime));
        // 0 和 1 不是素数
        not_prime[0] = not_prime[1] = 1;
        prime_sum = -1;
        for (i = 2; i < length; ++i) {
            if (!not_prime[i]) {
                prime[++prime_sum] = i;
            }
            // 这一段是精髓所在
            for (j = 0; j <= prime_sum; ++j) {
                if (i * prime[j] > length)
                    break;
                not_prime[i * prime[j]] = 1;
                if (i % prime[j] == 0)
                    break;
            }
        }
        result->length = ++prime_sum;
        int_array_copy(prime, result->data, length);
        return result;
    }
    // 如果需要的长度比求过的最大长度小，先计算出素数的数量再返回
    int_array_copy(prime, result->data, length);

    for (i = 0, j = 0; i < prime_sum && prime[i] < length; ++i, ++j);
    result->length = j;
    return result;
}


int main() {
    int i;
    Prime_Result *result = prime_Euler(10);
    for (i = 0; i < result->length; ++i)
        printf("%d ", result->data[i]);
    free(result);
    result = prime_Euler(6);
    printf("\n");
    for (i = 0; i < result->length; ++i)
        printf("%d ", result->data[i]);
    free(result);
    result = prime_Euler(20);
    printf("\n");
    for (i = 0; i < result->length; ++i)
        printf("%d ", result->data[i]);
    free(result);

    return 0;
}