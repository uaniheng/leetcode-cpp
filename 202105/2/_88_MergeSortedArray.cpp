//
// Created by GYC on 2021/5/11.
//

#include "../../common.h"

class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int i = m - 1, j = n - 1, curr = m + n - 1;
        while (i > -1 || j > -1) {
            if (i == -1) {
                nums1[curr--] = nums2[j--];
            } else if (j == -1) {
                nums1[curr--] = nums1[i--];
            } else if (nums1[i] > nums2[j]) {
                nums1[curr--] = nums1[i--];
            } else {
                nums1[curr--] = nums2[j--];
            }
        }
    }
};

int main() {
    vector<int> v1{1, 2, 3, 0, 0, 0}, v2{2, 5, 6};

    Solution().merge(v1, 3, v2, 3);

}