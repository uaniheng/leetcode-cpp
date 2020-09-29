//
// Created by gyc on 2020/9/29.
//

#include "../../common.h"

class Solution {
public:
    int rob(vector<int>& nums) {
        int pre0 = 0, pre1 = 0, temp;
        for(int n: nums) {
            temp = pre1;
            pre1 = max(n + pre0, pre1);
            pre0 = temp;
        }
        return pre1;
    }
};

int main() {

    vector<int> vec{1,2,3,1};
    cout << Solution().rob(vec) << endl;
}
