//
// Created by gyc on 2020/11/18.
//

#include "../../common.h"

class Solution {

private:
    bool canDrive(int start, vector<int>& gas, vector<int>& cost) {

        int len = gas.size();
        int oil = 0, index = start;
        do{
            index = index % len;
            oil += gas[index];
            oil -= cost[index];
            if (oil < 0) {
                return false;
            }
            ++index;
        }while (index != start);
        return true;
    }

public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for(int i = 0; i < gas.size(); ++i) {
            if (canDrive(i, gas, cost)) {
                return i;
            }
        }
        return -1;
    }
};

int main() {

    vector<int> gas{1,2,3,4,5}, cost{3,4,5,1,2};

    cout << Solution().canCompleteCircuit(gas, cost) << endl;
}
