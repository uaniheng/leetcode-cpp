//
// Created by gyc on 2020/9/29.
//

#include "../../common.h"

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int dp[n];
        for (int i = 0; i < n; ++i) {
            dp[i] = 1;
            for(int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp, dp + n);
    }
};

int main() {

    vector<int> vec{10, 9, 2, 5, 3, 7, 101, 18};
    cout << Solution().lengthOfLIS(vec) << endl;
}
