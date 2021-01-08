//
// Created by gyc on 2021/1/7.
//

#include "../../common.h"

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {

        int len = nums.size();
        for(int i = 0; i < len - 1; ++i) {

            int minIndex = i;
            for(int j = i + 1; j < len; ++j) {
                if(nums[j] < nums[minIndex]) {
                    minIndex = j;
                }
            }
            //swap(nums.begin() + i, nums.begin() + minIndex);
            iter_swap(nums.begin() + i, nums.begin() + minIndex);
        }
        return nums;
    }
};