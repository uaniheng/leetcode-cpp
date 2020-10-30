//
// Created by gyc on 2020/10/30.
//

#include "../../common.h"

class Solution {
public:
    int islandPerimeter(vector<vector<int>> &grid) {
        int res = 0;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    res += i > 0 ? (grid[i - 1][j] == 0 ? 1 : 0) : 1;
                    res += i + 1 < grid.size() ? (grid[i + 1][j] == 0 ? 1 : 0) : 1;
                    res += j > 0 ? (grid[i][j - 1] == 0 ? 1 : 0) : 1;
                    res += j + 1 < grid[0].size() ? (grid[i][j + 1] == 0 ? 1 : 0) : 1;
                }
            }
        }
        return res;
    }
};
