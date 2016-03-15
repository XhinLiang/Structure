#include <stdlib.h>
#include "array.h"

// 生成一个特定行列的二维数组，row 行，column 列 a[3][4] 三行四列
int **getIntArray(const int row, const int column) {
    int i;
    int **temp = (int **) malloc(row * sizeof(int *));
    for (i = 0; i < row; ++i) {
        temp[i] = (int *) malloc(column * sizeof(int));
    }
    return temp;
}
