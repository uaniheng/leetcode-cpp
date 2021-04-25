//
// Created by gyc on 2021/4/21.
//
#include "../../common_c.h"

int numDecodings(char* s) {
    int n = (int)strlen(s);
    int a = 0, b = 1, res = 0;
    for (int i = 1; i <= n; ++i) {
        res = 0;
        if (s[i - 1] != '0') {
            res += b;
        }
        if (i > 1 && s[i - 2] != '0' && ((s[i - 2] - '0') * 10 + (s[i - 1] - '0') <= 26)) {
            res += a;
        }
        a = b;
        b = res;
    }
    return res;
}

int main() {
    printf("%d", numDecodings("01"));
}