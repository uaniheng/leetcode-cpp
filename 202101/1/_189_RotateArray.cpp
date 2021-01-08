//
// Created by gyc on 2021/1/8.
//

#include "../../common.h"

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> res(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            res[(i + k) % nums.size()] = nums[i];
        }
        nums = res;
    }
};

int main() {

    vector<int> v{-1, -100, 3, 99};

    Solution().rotate(v, 2);
    for(auto i: v) {
        cout << i << endl;
    }

}