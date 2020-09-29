//
// Created by gyc on 2020/9/29.
//
#include "../../common.h"

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {

        int n = prices.size();

        int profit0 = 0;
        int profit1 = -prices[0];

        for(int i = 1; i < n; i ++) {
            profit0 = max(profit0, profit1 + prices[i] - fee);
            profit1 = max(profit1, profit0 - prices[i]);
        }
        return profit0;
    }
};

int main() {
    vector<int> vec{1, 3, 2, 8, 4, 9};
    cout << Solution().maxProfit(vec, 0) << endl;
}
