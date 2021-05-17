//
// Created by GYC on 2021/5/14.
//

#include "../../common.h"

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.length(), half = len / 2, res = 0;
        for(int i = 1; i < half + 1; ++i) {
            if (s[0] != s[i] || len % i != 0 ) {
                continue;
            }
            res = 1;
            for(int j = i; j < len; j += i) {
                for (int k = j, p = 0; k < j + i; ++k, ++p) {
                    if (s[k] != s[p]) {
                        res = 0;
                        break;
                    }
                }
                if (res == 0){
                    break;
                }
            }
            if (res == 1) {
                return true;
            }
        }
        return res == 1;
    }
};

int main() {
    cout << Solution().repeatedSubstringPattern("abab") << endl;
}