//
// Created by gyc on 2020/9/28.
//
#include "../../common.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        if (prices.empty()) return 0;
        int n = prices.size();

        int dp[n][3][2];
        dp[0][0][1] = -prices[0];
        dp[0][1][0] = 0;
        dp[0][1][1] = -prices[0];
        dp[0][2][0] = 0;
        dp[0][2][1] = -prices[0];

        for (int i = 1; i < n; ++i) {
            dp[i][2][0] = max(dp[i - 1][2][0], dp[i - 1][2][1] + prices[i]);
            dp[i][2][1] = max(dp[i - 1][2][1], dp[i - 1][1][0] - prices[i]);
            dp[i][1][0] = max(dp[i - 1][1][0], dp[i - 1][1][1] + prices[i]);
            dp[i][1][1] = max(dp[i - 1][1][1], - prices[i]);
        }
        return dp[n - 1][2][0];
    }
};

int main() {

    vector<int> vec{7,1,5,3,6,4};
    cout << Solution().maxProfit(vec) << endl;

}
