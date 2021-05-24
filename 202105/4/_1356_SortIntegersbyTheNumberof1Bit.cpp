//
// Created by GYC on 2021/5/24.
//
#include "../../common.h"

class Solution {
public:
    vector<int> sortByBits(vector<int> &arr) {
        vector<int> bit(10001, 0);
        for (int i = 1; i < 10001; ++i) {
            bit[i] = bit[i >> 1] + (i & 1);
        }
        sort(arr.begin(), arr.end(), [&](int x, int y) {
            if (bit[x] > bit[y]) {
                return false;
            }
            if (bit[x] < bit[y]){
                return true;
            }
            return x < y;
        });
        return arr;
    }
};

int main() {
    cout << (7 & 1) << endl;
}