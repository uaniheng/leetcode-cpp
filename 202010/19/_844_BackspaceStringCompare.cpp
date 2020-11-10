//
// Created by gyc on 2020/10/19.
//
#include "../../common.h"

class Solution {
public:
    bool backspaceCompare(string S, string T) {

        string s1, s2;

        for(char c: S) {
            if (c == '#') {

            }else {
                s1.append(c + "");
            }
        }
        for(char c: T) {
            if (c == '#') {
                s2.pop_back();
            }else {
                s2.append(c +"");
            }
        }
        return s1 == s2;
    }
};

int main () {

    cout << Solution().backspaceCompare("a##c", "#a#c");
}