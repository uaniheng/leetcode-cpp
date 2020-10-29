//
// Created by gyc on 2020/10/29.
//
#include "../../common.h"

class Solution {
public:
    int knapsack(int W, int N, vector<int>& wt, vector<int>& val) {

        vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));

        for(int i = 1; i <= N; ++i) {
            for(int j = 1; j <= W; ++j) {
                if (j < wt[i - 1]) {
                    dp[i][j] = dp[i - 1][j];
                }else {
                    dp[i][j] = max(dp[i - 1][j - wt[i - 1]] + val[i - 1],
                                   dp[i - 1][j]);
                }
            }
        }
        return dp[N][W];
    }
};
