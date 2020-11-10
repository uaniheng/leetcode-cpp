//
// Created by gyc on 2020/10/23.
//

#include "../../common.h"

class Solution {
private:
    static bool compare(vector<int> a, vector<int> b) {
        return a[1] < b[1];
    }

public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end(), compare);

        int count = 1, min_end = intervals[0][1];

        for(int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] > min_end) {
                count ++;
                min_end = intervals[i][1];
            }
        }
        return intervals.size() - count;
    }
};

int main() {
    //
    

}