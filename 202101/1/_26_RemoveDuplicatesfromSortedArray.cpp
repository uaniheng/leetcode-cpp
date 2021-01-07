//
// Created by gyc on 2021/1/7.
//

#include "../../common.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        int i = 0;
        for(int j = 1; j < nums.size(); ++j) {
            if (nums[i] != nums[j]) {
                i ++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};

int main() {
    vector<int> v{1,1,1,2,4,5,8};
    cout << Solution().removeDuplicates(v);
}