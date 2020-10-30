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
        vector<bool> dp(half + 1, false);
        dp[0] = true;
        for(int num : nums) {
            for (int j = half; j >= 0; --j) {
                if(j - num >= 0)
                    dp[j] = dp[j] || dp[j - num];
            }
        }
        return dp[half];
    }
};