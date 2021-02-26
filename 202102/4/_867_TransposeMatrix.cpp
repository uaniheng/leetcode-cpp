//
// Created by gyc on 2021/2/25.
//

#include "../../common.h"

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {

        int row = matrix.size(), col = matrix[0].size();
        auto res = vector(col, vector(row, 0));

        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                res[j][i] = matrix[i][j];
            }
        }
        return res;
    }
};
