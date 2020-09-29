//
// Created by gyc on 2020/9/29.
//
#include "../../common.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        if (n == 0) return n;
        int dp[n][2];
        dp[0][1] = -prices[0];
        dp[0][0] = 0;
        for (int i = 1;i < n; i ++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], (i > 2 ? dp[i - 2][0] : 0) - prices[i]);
        }
        return dp[n - 1][0];
    }
};

int main() {
    vector<int> vec{1,2,3,0,2};
    cout << Solution().maxProfit(vec) << endl;
}