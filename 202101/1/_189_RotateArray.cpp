//
// Created by gyc on 2021/1/8.
//

#include "../../common.h"

class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int n = nums.size();
        k %= n;
        int count = gcd(k, n);
        for(int start = 0; start < count; ++start) {
            int pre = start, preV=nums[start];
            do{
                int next = (pre + k)%n;
                swap(preV, nums[next]);
                pre = next;
            } while (pre != start);
        }
    }
};

int main() {

    vector<int> v{1,2,3,4,5,6,7};

    Solution().rotate(v, 3);
    for(auto i: v) {
        cout << i << endl;
    }

}