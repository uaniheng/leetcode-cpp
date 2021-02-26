//
// Created by gyc on 2020/12/9.
//
#include "../../common.h"

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector(n, 0));
        for(int i = 0; i < n; ++i) {
            dp[0][i] = 1;
        }
        for(int i = 0; i < m; ++i) {
            dp[i][0] = 1;
        }
        for(int i = 1; i < n; ++i) {
            for(int j = 1; j < m; ++j) {
                dp[j][i] = dp[j][i - 1] + dp[j - 1][i];
            }
        }
        return dp[m - 1][n - 1];
    }
};