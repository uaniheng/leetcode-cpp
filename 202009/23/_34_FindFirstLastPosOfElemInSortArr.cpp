//
// Created by gyc on 2020/9/23.
//
/**
 * 34. 在排序数组中查找元素的第一个和最后一个位置
 *
 * 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
 *
 */
#include "../../common.h"


class Solution {

public:

    int searchLeft(vector<int> &nums, int target) {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        if (left == nums.size() || nums[left] != target) return -1;
        return left;
    }

    int searchRight(vector<int> &nums, int target) {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        if (left == 0 || nums[left - 1] != target) return -1;
        return left - 1;
    }


    vector<int> searchRange(vector<int> &nums, int target) {
        if (nums.empty()) return vector<int>{-1, -1};
        int left = searchLeft(nums, target);
        int right = searchRight(nums, target);
        vector<int> *res = new vector<int>{left, right};

        return *res;
    }
};

int main() {

    // [-1,0,3,5,9,12]
    //2

    vector<int> vec{2, 2};
    auto v = Solution().searchRange(vec, 3);
    cout << v[0] << v[1] << endl;
}