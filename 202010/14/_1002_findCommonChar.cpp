//
// Created by gyc on 2020/10/14.
//

#include "../../common.h"

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {

        vector<string> res;

        int n = A.size();
        vector<vector<int>> temp = vector(26, vector(n, 0));

        for(int i = 0; i < A.size(); ++i) {
            const string &word = A[i];
            for(char c: word) {
                int index = c - 97;
                temp[index][i] ++;
            }
        }

        for(int i = 0; i < 26; ++i) {
            int min = INT32_MAX;
            for(int j = 0; j < n; ++j) {
                if (temp[i][j] < min){
                    min = temp[i][j];
                }
            }
            if (min > 0) {
                char c = i + 97;
                for(int k = 0; k < min; ++k) {
                    string s(1, c);
                    res.push_back(s);
                }
            }
        }
        return res;
    }
};


int main() {

    vector<string> vec{"bella","label","roller"};

    auto res = Solution().commonChars(vec);
    for(auto c: res) {
        cout << c << endl;
    }

}
