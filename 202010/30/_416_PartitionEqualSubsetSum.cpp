//
// Created by gyc on 2020/10/29.
//

#include "../../common.h"

class Solution {
public:
    bool canPartition(vector<int> &nums) {

        int sum = 0;
        for (int i: nums) sum += i;
        if (sum % 2 != 0) return false;

        int half = sum / 2;
        vector<vector<bool>> dp(nums.size() + 1, vector(half + 1, false));
        for (int i = 0; i <= nums.size(); ++i) dp[i][0] = true;

        for(int i = 1; i <= nums.size(); ++i) {
            for (int j = 1; j <= half; ++j) {
                if (j < nums[i - 1]) {
                    dp[i][j] = false;
                } else {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        return dp[nums.size()][half];
    }
};