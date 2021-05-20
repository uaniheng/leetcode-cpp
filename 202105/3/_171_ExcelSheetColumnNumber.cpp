//
// Created by GYC on 2021/5/20.
//

#include "../../common.h"

class Solution {
public:
    int titleToNumber(string columnTitle) {
        long sum = 0, factor = 1;
        for (int i = columnTitle.size() - 1; i > -1; --i) {
            sum += (columnTitle[i] - 'A' + 1) * factor;
            factor *= 26;
        }
        return sum;
    }
};

int main() {
    cout << Solution().titleToNumber("ZY") << endl;
}