//
// Created by gyc on 2020/10/14.
//

#include "../../common.h"

class Solution {
private:
    unordered_map<int, int> notes;

    int dp(int K, int N) {

        if (K == 1) return N;
        if (N == 0) return 0;

        int key = N * 100 + K;
        if (notes.count(key)) return notes[key];

        int res = INT32_MAX;

//        for(int i = 1; i < N + 1; ++i) {
//            res = min(res, max(dp(K, N - i), dp(K - 1, i - 1)) + 1);
//        }

        int lo = 1, hi = N, mid;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            int broken = dp(K - 1, mid - 1);
            int not_broken = dp(K, N - mid);
            if(broken > not_broken) {
                hi = mid - 1;
                res = min(res, broken + 1);
            } else {
                lo = mid + 1;
                res = min(res, not_broken + 1);
            }
        }
        notes[key] = res;
        return res;
    }

public:
    int superEggDrop(int K, int N) {
        return dp(K, N);
    }
};


int main() {

    cout << Solution().superEggDrop(4, 2000);
}