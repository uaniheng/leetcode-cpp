//
// Created by gyc on 2020/10/19.
//
#include "../../common.h"

class Solution {
private:
    string disposeStr(string &s) {
        string s2{};
        for(char c: s) {
            if (c == '#') {
                if (s2.length() > 0) {
                    s2.erase(s2.end() - 1);
                }
            }else {
                s2 +=c;
            }
        }
        cout << s2 << endl;
        return s2;
    }

public:
    bool backspaceCompare(string S, string T) {

        return disposeStr(S) == disposeStr(T);
    }
};

int main () {

    cout << Solution().backspaceCompare("ab#c", "ad#c");

    string s{};
    s.append("")
}