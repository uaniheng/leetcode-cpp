//
// Created by GYC on 2021/5/25.
//
#include "../../common.h"

class Solution {
public:
    int mySqrt(int x) {
        long l = 0, r = x;
        while(l <= r) {
            long mid = l + (r - l) / 2;
            long long pf = mid * mid;
            if (pf <= x) {
                l = mid + 1;
            } else if (pf > x) {
                r = mid - 1;
            }
        }
        return r;
    }
};

int main() {
    cout << Solution().mySqrt(4) << endl;
}