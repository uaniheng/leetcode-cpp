//
// Created by GYC on 2021/5/21.
//

#include "../../common.h"

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int m = 0, n = 0, len = nums.size();
        while (n < len) {
            if (nums[n] % 2 != 0) {
                int temp = nums[n];
                nums[n] = nums[m];
                nums[m] = temp;
                m++;
            }
            n++;
        }
        return nums;
    }
};