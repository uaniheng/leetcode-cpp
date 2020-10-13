//
// Created by gyc on 2020/9/29.
//
#include "../../common.h"

class Solution {

public:
    int minDistance(string word1, string word2) {

        int m = word1.size(), n = word2.size();
        if (m == 0 || n == 0) return n + m;

        int dp[m + 1][n + 1];

        for(int i = 0; i <= m; ++i) {
            dp[i][0] = i;
        }
        for(int i = 0; i <= n; ++i) {
            dp[0][i] = i;
        }

        for(int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[i - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } {
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};

int main() {

    cout << Solution().minDistance("apple", "rad");
}