//
// Created by gyc on 2020/8/6.
//
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        auto *result = new vector<int>;
        for(int i = 1; i <= nums.size(); i ++) {
            if (!mSet->count(i)) {
                result->push_back(i);
            }
        }
        return *result;
    }
};


int main() {
    vector<int> input{4,3,2,7,8,2,3,1};
    vector<int> result = Solution().findDisappearedNumbers(input);
    for(int i: result) {
        cout << i << endl;
    }

}