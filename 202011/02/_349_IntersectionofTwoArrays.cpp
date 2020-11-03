//
// Created by gyc on 2020/11/2.
//

#include "../../common.h"

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        unordered_set<int> mset{};
        vector<int> res{};

        for(int i: nums1) {
            mset.emplace(i);
        }
        for(int i: nums2) {
            if (mset.count(i)) {
                mset.erase(i);
                res.emplace_back(i);
            }
        }
        return res;
    }
};