//
// Created by gyc on 2020/11/4.
//

#include "../../common.h"

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        vector<vector<int>> res{};

        for(auto it = intervals.begin(); it != intervals.end(); ++it) {
            if (newInterval[1] < (*it)[0]) {
                res.push_back(newInterval);
                res.insert(res.end(), it, intervals.end());
                return res;
            }
            if (newInterval[0] <= (*it)[1] && newInterval[1] >= (*it)[0]) {
                newInterval[0] = min(newInterval[0], (*it)[0]);
                newInterval[1] = max(newInterval[1], (*it)[1]);
                continue;
            }
            if (newInterval[0] > (*it)[1]) {
                res.push_back(*it);
            }
        }
        res.push_back(newInterval);
        return res;
    }
};

int main() {

    vector<vector<int>> intervals{{1,2},{3,5},{6,7},{8,10},[12,16]};
    vector<int> newInterval{2,5};

    auto res = Solution().insert(intervals, newInterval);

    for(auto v: res) {
        cout << v[0] << "," << v[1] << endl;
    }

}