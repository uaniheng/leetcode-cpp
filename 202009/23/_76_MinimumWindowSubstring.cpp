//
// Created by gyc on 2020/9/23.
//

#include "../../common.h"

class Solution {

public:
    string minWindow(string s, string t) {

        int minLen = s.size() + 1;
        string res;

        unordered_map<char, int> needs{};
        unordered_map<char, int> window{};
        int match = 0;

        for (char c: t) { needs[c]++; }

        int left = 0, right = 0;
        while (right < s.size()) {
            if (needs.count(s[right])) {
                window[s[right]] ++;
                if (window[s[right]] == needs[s[right]]) {
                    match ++;
                }
            }
            while (match == needs.size()) {
                int len = right - left + 1;
                if (len < minLen) {
                    minLen = len;
                    res = s.substr(left, len);
                }
                if (window.count(s[left])) {
                    window[s[left]] --;
                    if (window[s[left]] < needs[s[left]]) {
                        match --;
                    }
                }
                left ++;
            }
            right ++;
        }
        return res;
    }
};

int main() {

    string s = "ADOBECODEBANC", t = "ABC";

    cout << Solution().minWindow(s, t) << endl;
}