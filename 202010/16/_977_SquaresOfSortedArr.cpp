//
// Created by gyc on 2020/10/16.
//
#include "../../common.h"

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {

        int neg = -1;
        for(int i = 0; i < A.size(); ++i) {
            if (A[i] < 0) {
                neg = i;
            }
        }

        vector<int> res{};

        int pos = neg + 1;

        while (neg > -1 || pos < A.size()) {

            if (neg < 0) {
                res.push_back(A[pos] * A[pos]);
                pos ++;
            }else if (pos == A.size()) {
                res.push_back(A[neg] * A[neg]);
                neg --;
            }else if (A[neg] * A[neg] > A[pos] * A[pos]) {
                res.push_back(A[pos] * A[pos]);
                pos ++;
            }else {
                res.push_back(A[neg] * A[neg]);
                neg --;
            }
        }
        return res;
    }
};

int main() {
    vector<int> vec{-4,-1,0,3,10};

    auto res = Solution().sortedSquares(vec);

    for(int i: res) {
        cout << i << endl;
    }

}