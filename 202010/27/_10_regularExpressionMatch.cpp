//
// Created by gyc on 2020/10/27.
//

#include "../../common.h"

class Solution {
private:
    unordered_map<int, bool> memo{};

    bool dp(string &s, string &p, int i, int j) {
        int key = i * 100 + j;
        if (memo.count(key)) {
            return memo[key];
        }
        if (j == p.length()) {
            return i == s.length();
        }
        bool first = i < s.length() and (p[j] == s[i] or p[j] == '.');
        bool res;
        if (j + 1 < p.length() && p[j + 1] == '*') {
            res = dp(s, p, i, j + 2) || first and dp(s, p, i + 1, j);
        }else {
            res = first && dp(s, p, i + 1, j + 1);
        }
        memo[key] = res;
        return res;
    }


public:
    bool isMatch(string s, string p) {
        return dp(s, p, 0, 0);
    }
};