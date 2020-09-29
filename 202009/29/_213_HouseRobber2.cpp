//
// Created by gyc on 2020/9/29.
//
#include "../../common.h"

class Solution {

private:
    int rob(vector<int>& nums, int begin, int end) {

        int pre0 = 0, pre1 = 0, temp;
        for(int i = begin; i < end; i ++) {
            temp = pre1;
            pre1 = max(pre1, pre0 + nums[i]);
            pre0 = temp;
        }
        return pre1;
    }


public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        return max(rob(nums, 0, nums.size() - 1),
                   rob(nums, 1, nums.size()));

    }
};

int main() {

    vector<int> vec{};
    cout << Solution().rob(vec) << endl;
}