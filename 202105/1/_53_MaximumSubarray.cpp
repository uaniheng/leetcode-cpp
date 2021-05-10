//
// Created by GYC on 2021/5/10.
//
#include "../../common.h"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max1 = nums[0], pre = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            if (pre + nums[i] > nums[i]) {
                pre = pre + nums[i];
            } else{
                pre = nums[i];
            }
            max1 = max(max1, pre);
        }
        return max1;
    }
};

int main() {
    vector<int> v{-2,1};
    cout << Solution().maxSubArray(v) << endl;
}