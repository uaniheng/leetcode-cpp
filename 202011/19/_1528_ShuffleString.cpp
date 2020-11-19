//
// Created by gyc on 2020/11/19.
//

#include "../../common.h"

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {

        // 冒泡排序
        for(int i = s.size(); i > 0; --i) {
            for(int j = 0; j < i - 1; ++j) {
                if(indices[j] > indices[j + 1]) {
                    int t1 = indices[j];
                    indices[j] = indices[j + 1];
                    indices[j + 1] = t1;

                    char t2 = s[j];
                    s[j] = s[j + 1];
                    s[j + 1] = t2;
                }
            }
        }
        return s;
     }
};

int main() {

    string s = "abc";
    vector<int> indices{0,1,2};

    cout << Solution().restoreString(s, indices) << endl;
}