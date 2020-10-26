//
// Created by gyc on 2020/10/26.
//

#include "../../common.h"

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums) {
        vector<pair<int, int>> data{};
        data.reserve(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            data.emplace_back(nums[i], i);
        }
        sort(data.begin(), data.end());

        vector<int> res(nums.size(), 0);
        int pre = -1;
        for(int i = 0; i < data.size(); ++i) {
            if (pre == -1 || data[i].first != data[i - 1].first) {
                pre = i;
            }
            res[data[i].second] = pre;
        }
        return res;
    }
};

int main() {


}
