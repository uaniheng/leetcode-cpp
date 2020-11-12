//
// Created by gyc on 2020/11/12.
//

#include "../../common.h"

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int> &A) {
        // [4,2,5,7]
        for(int i = 0, j = 1; i < A.size(); i += 2) {

            if (A[i] % 2) {
                while (A[j] % 2) {
                    j += 2;
                }
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
        return A;
    }
};

int main() {

    vector<int> v{4,2,5,7};

    auto res = Solution().sortArrayByParityII(v);
    for(auto i: res) {
        cout << i << endl;
    }
}