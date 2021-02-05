//
// Created by gyc on 2021/2/5.
//

#include "../../common.h"

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int begin = 0, end = k - 1, sum = 0, length = nums.size();
        for(int i = 0; i < k; ++i) {
            sum += nums[i];
        }
        int max = sum;
        while (++end < length) {
            sum = sum - nums[begin ++] + nums[end];
            if (sum > max) {
                max = sum;
            }
        }
        return (double)max / k;
    }
};

int main() {

    vector<int> v{1,12,-5,-6,50,3};
    double res = Solution().findMaxAverage(v, 4);
    cout << res << endl;
}