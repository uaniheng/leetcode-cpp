//
// Created by GYC on 2021/5/10.
//

#include "../../common.h"

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> c(rowIndex + 1);
        for(int i = 0; i <=rowIndex; ++i) {
            c[i].resize(i + 1);
            c[i][0] = c[i][i] = 1;


        }
    }
};