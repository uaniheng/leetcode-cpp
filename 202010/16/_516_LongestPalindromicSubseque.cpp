//
// Created by gyc on 2020/10/16.
//

#include "../../common.h"

class Solution {
public:
    int longestPalindromeSubseq(string s) {

        int n = s.size();
        int dp[n][n];

        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }

        for (int i = 1; i < n; ++i) {
            for (int j = 0, ii = i; ii < n; ++ii, ++j) {
                if (s[j] == s[ii]) {
                    if (j + 1 > ii - 1) {
                        dp[j][ii] = 2;
                    } else {
                        dp[j][ii] = dp[j + 1][ii - 1] + 2;
                    }
                } else {
                    dp[j][ii] = max(dp[j][ii - 1], dp[j + 1][ii]);
                }
            }
        }

        return dp[0][n - 1];
    }
};

int main() {

    cout << Solution().longestPalindromeSubseq("bbbab") << endl;

}