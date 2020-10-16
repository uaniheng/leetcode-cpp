//
// Created by gyc on 2020/10/16.
//
#include "../../common.h"

class Solution {
public:
    vector<int> sortedSquares(vector<int> &A) {


        int n = A.size();
        vector<int> res(n);
        for (int i = 0, j = n - 1, pos = n - 1; i <= j;) {

            if (A[i] * A[i] > A[j] * A[j]) {
                res[pos] = A[i] * A[i];
                ++i;
            } else {
                res[pos] = A[j] * A[j];
                --j;
            }
            --pos;
        }
        return res;
    }
};

int main() {
    vector<int> vec{-4, -1, 0, 3, 10};

    auto res = Solution().sortedSquares(vec);

    for (int i: res) {
        cout << i << endl;
    }
}