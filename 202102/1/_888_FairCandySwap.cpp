//
// Created by gyc on 2021/2/1.
//

#include "../../common.h"

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {

        int sumA = 0, sumB = 0, gap;
        unordered_set<int> note{};

        for(int &i: A) {
            sumA += i;
        }
        for(int &i: B) {
            sumB += i;
        }
        gap = (sumA - sumB) / 2;

        for(int i = 0; i < A.size(); ++i) {
            note.emplace(A[i] - gap);
        }
        for(int & i : B) {
            if (note.count(i)) {
                return {i + gap, i};
            }
        }
        return {};
    }
};

int main() {

    vector<int> v1{1,1}, v2{2,2};

    auto res = Solution().fairCandySwap(v1, v2);
    for(auto &i: res) {
        cout << i << endl;
    }
}