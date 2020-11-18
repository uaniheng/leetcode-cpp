//
// Created by gyc on 2020/11/18.
//

#include "../../common.h"

/**
 *
 * 画图
 * 1. 最终油量剩余>=0时，才能走全程
 * 2. 一次遍历，油量最低点的下一站是出发站
 */
class Solution {

public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {

        int curr = gas[0] - cost[0];
        vector<int> min{0, gas[0] - cost[0]};
        for (int i = 1; i < gas.size(); ++i) {
            curr += gas[i] - cost[i];
            if (curr < min[1]) {
                min[0] = i;
                min[1] = curr;
            }
        }
        if (curr >= 0) {
            return (min[0] + 1) % gas.size();
        }
        return -1;
    }
};

int main() {


    vector<int> gas{3,1,1}, cost{1,2,2};

    cout << Solution().canCompleteCircuit(gas, cost) << endl;
}
