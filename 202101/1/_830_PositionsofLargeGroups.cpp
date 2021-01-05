//
// Created by gyc on 2021/1/5.
//

#include "../../common.h"

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> res{};

        auto last = pair<int, int>(s[0], 0);
        for(int i = 1; i < s.length(); ++i) {
            if (last.first != s[i]) {
                if (i - last.second >= 3) {
                    res.push_back({last.second, i - 1});
                }
                last.first = s[i];
                last.second = i;
            }
        }
        if(last.first == s[s.length() - 1] && s.length() - last.second >= 3){
            res.push_back({last.second, (int)s.length() - 1});
        }
        return res;
    }
};