//
// Created by GYC on 2021/5/20.
//

#include "../../common.h"

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res = 0;
        for(char c: columnTitle) {
            res = res * 26 + (c - 'A' + 1);
        }
        return res;
    }
};

int main() {
    cout << Solution().titleToNumber("ZY") << endl;
}