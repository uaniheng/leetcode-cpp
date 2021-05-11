//
// Created by GYC on 2021/5/11.
//

#include "../../common.h"

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0, maxSum;
        for(int i = 0; i < k; ++i) {
            sum += nums[i];
        }
        maxSum = sum;
        for(int i = k; i < nums.size(); ++i) {
            sum = sum + nums[i] - nums[i - k];
            maxSum = max(sum, maxSum);
        }
        return (double)maxSum / k;
    }
};

int main() {
}
