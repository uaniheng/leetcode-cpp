//
// Created by GYC on 2021/5/11.
//

#include "../../common.h"

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int begin = 0, end = nums.size(), mid;
        while (begin < end) {
            mid = (begin + end) / 2;
            if (nums[mid] == mid) {
                begin = mid + 1;
            }else {
                end = mid;
            }
        }
        return begin;
    }
};