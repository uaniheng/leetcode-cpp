//
// Created by gyc on 2020/11/12.
//
#include "../../common.h"

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.empty()) return;
        int s = nums.size() - 2;
        while (s >= 0 && nums[s] >= nums[s + 1]){
            --s;
        }
        if (s >= 0) {
            int l = nums.size() - 1;
            while (l >= s && nums[l] <= nums[s]) {
                --l;
            }
            swap(nums[s],nums[l]);
        }
        reverse(nums.begin() + s + 1, nums.end());
    }
};

int main() {

    vector<int> res{1,5,1};

    Solution().nextPermutation(res);

    for (auto i: res) {
        cout << i << endl;
    }
}