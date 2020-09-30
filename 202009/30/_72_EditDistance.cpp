//
// Created by gyc on 2020/9/29.
//
#include "../../common.h"

class Solution {

private:
private:
    unordered_map<string, int> note;


    int dp(int i, int j, string &w1, string &w2) {
        string key = to_string(i) + ":" + to_string(j);
        if (note.count(key)) return note[key];
        if (i == -1 || j == -1) return max(i, j) + 1;

        if (w1[i] == w2[j]) {
            return dp(i - 1, j - 1, w1, w2);
        }
        int res = min({dp(i - 1, j - 1, w1, w2) + 1,
                       dp(i, j - 1, w1, w2) + 1,
                       dp(i - 1, j, w1, w2) + 1});
        note[key] = res;
        return res;
    }

public:
    int minDistance(string word1, string word2) {

        return dp(word1.size() - 1, word2.size() - 1, word1, word2);
    }
};

int main() {

    cout << Solution().minDistance("horse", "ros");
}