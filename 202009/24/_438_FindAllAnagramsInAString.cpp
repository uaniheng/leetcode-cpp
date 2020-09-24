//
// Created by gyc on 2020/9/24.
//

#include "../../common.h"

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> res{};

        unordered_map<char, int> needs{};
        unordered_map<char, int> windows{};

        int left = 0, right = 0, match = 0;
        for(char c: p) {needs[c] ++;}
        while(right < s.size()) {
            char c = s[right];
            if (needs.count(c)){
                windows[c] ++;
                if (windows[c] == needs[c]){
                    match ++;
                }
            }
            if (right - left + 1 == p.size()) {
                if (match == needs.size()) {
                    res.push_back(left);
                }
                if (windows.count(s[left])) {
                    if (windows[s[left]] == needs[s[left]]) {
                        match --;
                    }
                    windows[s[left]] --;

                }
                left ++;
            }
            right ++;
        }
        return res;
    }
};


int main() {

    string s = "baa", t = "aa";

    auto res = Solution().findAnagrams(s, t);
    for(int i: res) {
        cout << i << endl;
    }
}