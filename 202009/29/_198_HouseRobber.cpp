//
// Created by gyc on 2020/9/29.
//

#include "../../common.h"

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int dp[n + 1];
        dp[n - 1] = nums[n - 1];
        dp[n] = 0;

        for(int i = n - 2; i >=0; i --) {
            dp[i] = max(dp[i + 1], nums[i] + dp[i + 2]);
        }
        return dp[0];
    }
};

int main() {

    vector<int> vec{1,2,3,1};

    cout << Solution().rob(vec) << endl;

}
