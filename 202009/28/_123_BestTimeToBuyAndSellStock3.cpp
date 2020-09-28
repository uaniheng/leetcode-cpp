//
// Created by gyc on 2020/9/28.
//
#include "../../common.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        if (prices.empty()) return 0;
        int n = prices.size();

        int dp10 = 0, dp11 = -prices[0], dp20 = 0, dp21 = -prices[0];
        for (int i = 0; i < n; ++i) {
            dp10 = max(dp10, dp11 + prices[i]);
            dp11 = max(dp11, -prices[i]);
            dp20 = max(dp20, dp21 + prices[i]);
            dp21 = max(dp21, dp10 - prices[i]);
        }
        return dp20;
    }
};

int main() {

    vector<int> vec{7,1,5,3,6,4};
    cout << Solution().maxProfit(vec) << endl;

}
