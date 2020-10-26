//
// Created by gyc on 2020/10/26.
//
#include "../../common.h"

class kmp {

private:
    vector<vector<int>> dp;
    string pat;

public:

    explicit kmp(string pat) {
        int M = pat.length();
        this->pat = pat;
        this->dp = vector(M, vector<int>(256, 0));
        dp[0][pat[0]] = 1;
        int X = 0;

        for(int j = 1; j < M; ++j) {
            for(int c = 0; c < 256; ++c) {
                if (pat[j] == c) {
                    dp[j][c] = j + 1;
                }else {
                    dp[j][c] = dp[X][c];
                }
            }
//            cout << X << "," << pat[j] << "->";
//            X = dp[X][pat[j]];
//            cout << X << endl;
        }
    }

    int search(string txt) {
        int M = pat.length();
        int N = txt.length();
        int j = 0;
        for(int i = 0; i < N; ++ i) {
            j = dp[j][txt[i]];
            if (j == M) return i - M + 1;
        }
        return -1;
    }

};

int main() {
    kmp k("abcqwe");

    cout << k.search("sfsdfasfeefsdf") << endl;
}
