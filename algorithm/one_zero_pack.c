/**
 * 经典的动态规划问题 - 01背包
 * 背包容量为 max_weight，山洞里东西数量为 sum，
 * 第 i 个东西体积为 weight[i]，价值为 value[i]
 * 求能得到的最大价值
 **/
#include<stdio.h>
#include<string.h>
#include "../util/common.h"

int main(){
    int dp[101][1001], sum, max_weight;
    int weight[101], value[101];
    int i, j;
    memset(dp, 0, sizeof(dp));
    scanf("%d%d", &max_weight, &sum);
    for(i = 1; i <= sum ; ++i) {
        scanf("%d%d", weight + i, value +i);
    }
    for(i = 1; i <= sum ; ++i) {
        for(j = 0; j <= max_weight ; ++j) {
            if(j >= weight[i]) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    printf("%d\n", dp[sum][max_weight]);
    return 0;
}
