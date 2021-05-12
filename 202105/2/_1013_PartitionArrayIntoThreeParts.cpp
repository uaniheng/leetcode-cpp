//
// Created by GYC on 2021/5/12.
//

#include "../../common.h"

class Solution {
public:
    bool canThreePartsEqualSum(vector<int> &arr) {
        int s = accumulate(arr.begin(), arr.end(), 0);
        if (s % 3 != 0) {
            return false;
        }
        int target = s / 3;
        int n = arr.size();
        int sum = 0, i = 0;
        while (i < n - 2) {
            sum += arr[i++];
            if (sum == target){
                break;
            }
        }
        if (sum != target) {
            return false;
        }
        while (i < n - 1) {
            sum += arr[i++];
            if (sum == target * 2) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    vector<int> v{18,12,-18,18,-19,-1,10,10};
    cout << Solution().canThreePartsEqualSum(v) << endl;
}