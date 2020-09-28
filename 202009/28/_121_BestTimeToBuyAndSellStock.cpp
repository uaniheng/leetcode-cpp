//
// Created by gyc on 2020/9/25.
//

#include "../../common.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int n = prices.size();
        int profit0 = 0, profit1 = -prices[0];
        for (int i = 1; i < n; i++) {
            profit0 = max(profit0, profit1 + prices[i]);
            profit1 = max(profit1, -prices[i]);
        }
        return profit0;
    }
};

int main() {

    vector<int> vec{7,1,5,3,6,4};
    cout << Solution().maxProfit(vec) << endl;

}