//
// Created by gyc on 2020/11/19.
//

#include "../../common.h"

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        for(int right = 0; right < nums.size(); ++right) {
            if (nums[right] != 0) {
                if (left == right) {
                    ++left;
                } else {
                    nums[left++] = nums[right];
                    nums[right] = 0;
                }
            }
        }
    }
};