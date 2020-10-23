//
// Created by gyc on 2020/10/23.
//
#include "../../common.h"

class Solution {

public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) return 0;

        sort(points.begin(), points.end(), [](const vector<int> &o1, const vector<int> &o2) {
            return (o1[1] < o2[1]);
        });

        int count = 1, min_end = points[0][1];

        for(int i = 1; i < points.size(); ++i) {

            if (points[i][0] >= min_end) {
                count ++;
                min_end = points[i][1];
            }
        }
        return count;
    }
};
