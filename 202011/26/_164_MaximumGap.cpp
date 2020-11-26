//
// Created by gyc on 2020/11/26.
//

#include "../../common.h"

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(), nums.end(),[](int &a, int &b){
            return a < b;
        });
        int res = 0;
        for(int i = 1; i < nums.size(); ++i) {
            res = max(res, nums[i] - nums[i - 1]);
        }
        return res;
    }
};