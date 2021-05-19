//
// Created by GYC on 2021/5/19.
//
#include "../../common.h"

class Solution {

private:
    void reversStr(string &s, int begin, int end) {
        while (begin < end) {
            char temp = s[begin];
            s[begin++] = s[end];
            s[end--] = temp;
        }
    }

public:
    string reverseWords(string s) {
        // reversStr(s, 0, s.length() - 1);
        int last = 0;
        for(int i = 0, len = s.length(); i < len; ++i) {
            if (s[i] == ' ') {
                reversStr(s, last, i - 1);
                last = i + 1;
            }
        }
        reversStr(s, last, s.length() - 1);
        return s;
    }
};

int main() {
    cout << Solution().reverseWords("1234 5678 abcd") << endl;
}