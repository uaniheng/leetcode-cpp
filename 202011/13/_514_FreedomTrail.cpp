//
// Created by gyc on 2020/11/11.
//


#include "../../common.h"

class Solution {
public:
    int findRotateSteps(string ring, string key) {

        int rl = ring.length(), kl = key.length();
        vector<vector<int>> dp = vector(kl, vector(rl, 0x3f3f3f3f));
        vector<vector<int>> pos = vector(26, vector<int>());
        for (int i = 0; i < ring.size(); ++i) {
            pos[ring[i] - 'a'].emplace_back(i);
        }
        for (auto i: pos[key[0] - 'a']) {
            dp[0][i] = min(i, rl - i) + 1;
        }
        for (int i = 1; i < kl; ++i) {
            for (auto j: pos[key[i] - 'a']) {
                for (auto k: pos[key[i - 1] - 'a']) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + min(abs(k - j), rl - abs(k - j)) + 1);
                }
            }
        }
        return *min_element(dp[kl - 1].begin(), dp[kl - 1].end());
    }
};

int main() {

    cout << Solution().findRotateSteps("godding", "gd") << endl;
}