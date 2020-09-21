//
// Created by gyc on 2020/9/16.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount < 1) return 0;
        int *dp = new int[amount + 1]{0};
        int &arr = *dp;
        for (int i = 1; i <= amount; ++i) {
            dp[i] = amount + 1;
        }

        for(int i = 1; i <= amount; i ++) {
            for (int coin: coins) {
                if (i >= coin) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        return dp[amount] == amount + 1 ? -1:dp[amount];
    }
};

int main() {

    auto vec = new vector<int>{2};
    cout << Solution().coinChange(*vec, 3);
}
