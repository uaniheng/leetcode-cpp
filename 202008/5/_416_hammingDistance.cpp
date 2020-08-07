//
// Created by gyc on 2020/8/5.
//
#include <iostream>
using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int r = x ^ y;
        int distance = 0;
        while (r) {
            r &= r - 1;
        }
        return distance;
    }
};

int main() {
    cout << Solution().hammingDistance(123456, 123459);
}