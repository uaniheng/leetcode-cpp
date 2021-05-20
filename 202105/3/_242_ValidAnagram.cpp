//
// Created by GYC on 2021/5/20.
//

#include "../../common.h"

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};