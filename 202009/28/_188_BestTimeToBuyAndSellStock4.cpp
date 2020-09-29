//
// Created by gyc on 2020/9/28.
//
#include "../../common.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int profit0 = 0, profit1 = -prices[0];
        for (int i = 1; i < n; i ++) {
            profit0 = max(profit0, profit1 + prices[i]);
            profit1 = max(profit1, profit0 - prices[i]);
        }
        return profit0;
    }


    int maxProfit(int k, vector<int>& prices) {

        if (prices.empty()) { return 0;}

        if (k >= prices.size() / 2) {return maxProfit(prices);}

        int n = prices.size();

        //int dp[n][k + 1][2];
        //vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(k + 1, vector<int>(2, 0)));
        int dp[k + 1][2];
        for (int i = 0; i <= k; i ++) {
            dp[i][0] = 0;
            dp[i][1] = -prices[0];
        }

        for(int i = 1; i < n; i ++) {
            for(int j = k; j > 0; j --) {
                dp[j][0] = max(dp[j][0], dp[j][1] + prices[i]);
                dp[j][1] = max(dp[j][1], dp[j - 1][0] - prices[i]);
            }
        }
        return dp[k][0];
    }
};

int main() {
    vector<int> vec{3,2,6,5,0,3};
    cout << Solution().maxProfit(2, vec) << endl;
}
