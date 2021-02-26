//
// Created by gyc on 2020/12/14.
//

#include "../../common.h"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> note{};

        for(auto it = strs.begin(); it != strs.end(); ++it) {
            string s = *it;
            sort(s.begin(), s.end());
            note[s].emplace_back(*it);
        }

        vector<vector<string>> res{};
        for(auto &v: note) {
            res.emplace_back(v.second);
        }
        return res;
    }
};

int main() {
    vector<string> v{"ate","eat","tea","nat","tan","bat"};

    auto res = Solution().groupAnagrams(v);

    cout << res.size() << endl;
}