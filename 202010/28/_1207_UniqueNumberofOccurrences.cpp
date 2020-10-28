//
// Created by gyc on 2020/10/28.
//
#include "../../common.h"

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m{};

        for(int i: arr) {
            m[i] ++;
        }

        unordered_set<int> s{};

        for(auto & it : m) {
            if (s.count(it.second)) {
                return false;
            }else {
                s.emplace(it.second);
            }
        }
        return true;
    }
};