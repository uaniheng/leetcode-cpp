//
// Created by gyc on 2020/12/23.
//
#include "../../common.h"

class Solution {
public:
    int firstUniqChar(string s) {

        vector<char> t(26, 0);
        for(int i = 0; i < s.length(); ++i) {
            int key = s[i] - 'a';
            if (t[key] <= 1) {
                ++t[key];
            }
        }
        for(int i = 0; i < s.length(); ++i) {
            if (t[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};

int main() {

    cout << Solution().firstUniqChar("leetcode");
}