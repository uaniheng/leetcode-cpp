//
// Created by gyc on 2020/10/15.
//
#include "../../common.h"

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int peak = 0;
        for(int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[peak]) {
                peak = i;
            }
        }
        return peak;
    }
};

int main() {

    vector<int> vec{1,2,3,1};
    cout << Solution().findPeakElement(vec) << endl;
}