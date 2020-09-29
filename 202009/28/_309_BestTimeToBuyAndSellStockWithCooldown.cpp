//
// Created by gyc on 2020/9/29.
//
#include "../../common.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        if (n == 0) return n;

        int profit0 = 0, profit1 = -prices[0], profitPre0 = 0;
        for (int i = 1;i < n; i ++) {
            int temp = profit0;
            profit0 = max(profit0, profit1 + prices[i]);
            profit1 = max(profit1, profitPre0 - prices[i]);
            profitPre0 = temp;
        }
        return profit0;
    }
};

int main() {
    vector<int> vec{1,2,3,0,2};
    cout << Solution().maxProfit(vec) << endl;
}