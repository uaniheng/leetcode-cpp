//
// Created by gyc on 2021/1/7.
//

#include "../../common.h"

class Solution {

private:
    void randomized_quicksort(vector<int> &nums, int l, int r) {
        if (l >= r) {
            return;
        }
        int i = rand() % (r - l + 1) + l;
        swap(nums[i], nums[r]);
        int smallIndex = l - 1;
        for (int j = l; j < r; ++j) {
            if (nums[j] < nums[r]) {
                swap(nums[++smallIndex], nums[j]);
            }
        }
        swap(nums[smallIndex + 1], nums[r]);
        randomized_quicksort(nums, l, smallIndex);
        randomized_quicksort(nums, smallIndex + 2, r);
    }

public:
    vector<int> sortArray(vector<int> &nums) {
        srand((unsigned) time(NULL));
        randomized_quicksort(nums, 0, (int) nums.size() - 1);
        return nums;
    }
};