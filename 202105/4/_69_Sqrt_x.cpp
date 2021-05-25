//
// Created by GYC on 2021/5/25.
//
#include "../../common.h"

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0){
            return 0;
        }
        int r = exp(0.5 * log(x));
        return (long long)(r + 1) * (r + 1) <= x ? r + 1:r;
    }
};