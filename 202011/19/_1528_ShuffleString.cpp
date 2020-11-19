//
// Created by gyc on 2020/11/19.
//

#include "../../common.h"

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string res(s.size(), 0);
        for(int i = 0; i< s.size(); ++i) {
            res[indices[i]] = s[i];
        }
        return res;
     }
};

int main() {

    string s = "abc";
    vector<int> indices{0,1,2};

    cout << Solution().restoreString(s, indices) << endl;
}