//
// Created by gyc on 2020/9/23.
//

#include "../../common.h"

class Solution {

public:
    string minWindow(string s, string t) {

        int minLen = s.size() + 1;
        string res;

        map<char, int> needs{};

        for (char c: t) { needs[c]++; }

        for (int i = 0; i < s.size(); i++) {
            int match = 0;
            map<char, int> window{};
            for (int j = i; j < s.size(); j++) {
                if (needs.count(s[j])) {
                    window[s[j]]++;
                    if (window[s[j]] == needs[s[j]]) {
                        match ++;
                    }
                }
                if (match == needs.size()) {
                    int len = j - i + 1;
                    if (len < minLen) {
                        minLen = len;
                        res = s.substr(i, len);
                    }
                    break;
                }
            }
        }
        return res;
    }
};

int main() {

    string s = "a", t = "a";

    cout << Solution().minWindow(s, t) << endl;
}