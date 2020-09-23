//
// Created by gyc on 2020/9/22.
//

#include "../../common.h"

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            }else if(nums[mid] == target) {
                left = mid + 1;
            } else if(nums[mid] > target) {
                right = mid;
            }
        }
        if (left == nums.size()) return -1;
        return left - 1;
    }
};

int main() {

    // [-1,0,3,5,9,12]
    //2

    vector<int> vec{-1,2,2,3,3,3,5};
    cout << Solution().search(vec, 4) << endl;
}
