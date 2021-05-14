//
// Created by GYC on 2021/5/13.
//

#include "../../common.h"

class Solution {
private:

public:
    string addStrings(string num1, string num2) {
        int m = num1.size() - 1, n = num2.size() - 1, curr = 0;
        vector<char> res(max(m, n) + 2,  '0');
        while (m > -1 || n > -1) {
            int a = m > -1 ? num1[m--] - '0' : 0;
            int b = n > -1 ? num2[n--] - '0' : 0;
            int c = a + b;
            c += res[curr] - '0';
            res[curr] = (c % 10) + '0';
            curr++;
            res[curr] = (c / 10) + '0';
        }
        string s;
        for(int i = res.size() - 1; i > -1; --i) {
            if (i == res.size() - 1 && res[i] == '0') {
                continue;
            }
            s += res[i];
        }
        return s;
    }
};

int main() {
    cout << Solution().addStrings("123", "5678") << endl;
}