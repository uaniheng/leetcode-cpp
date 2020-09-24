//
// Created by gyc on 2020/9/24.
//

#include "../../common.h"
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() < 2) return s.length();
        int left = 0, right = 0, maxLen = 0;
        unordered_map<char, int> contain{};
        while (right < s.size()) {
            char c = s[right];
            if(contain.count(c)) {
                if (contain[c] >= left) {
                    left = contain[c] + 1;
                }
            }
            contain[c] = right;
            int len = right - left + 1;
            maxLen = max(len, maxLen);
            right ++ ;
        }
        return maxLen;
    }
};

int main() {

    string input = "abcabcbb";
    cout << Solution().lengthOfLongestSubstring(input) << endl;

}