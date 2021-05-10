//
// Created by gyc on 2020/11/19.
//

#include "../../common.h"

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {

        for(int i = 0; i < s.size(); ++i) {
            if(indices[i] == i) {
                continue;
            }

            char temp = s[indices[i]];
            s[indices[i]] = s[i];
            int to = indices[indices[i]];


        }
        return s;
     }
};

int main() {

    string s = "abc";
    vector<int> indices{0,1,2};
    cout << Solution().restoreString(s, indices) << endl;
}