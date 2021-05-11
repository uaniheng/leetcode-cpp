//
// Created by GYC on 2021/5/11.
//

#include "../../common.h"

class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int i = 0, j = 0, curr = 0;
        int res[m + n];
        while (i < m || j < n) {
            if (i == m) {
                res[curr++] = nums2[j++];
            } else if (j == n) {
                res[curr++] = nums1[i++];
            } else if (nums1[i] < nums2[j]) {
                res[curr++] = nums1[i++];
            } else {
                res[curr++] = nums2[j++];
            }
        }
        for (int a = 0; a < nums1.size(); ++a) {
            nums1[a] = res[a];
        }
    }
};

int main() {
    vector<int> v1{1, 2, 3, 0, 0, 0}, v2{2, 5, 6};

    Solution().merge(v1, 3, v2, 3);

}