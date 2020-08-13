//
// Created by gyc on 2020/8/7.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        auto *temp = new vector<int>{nums};
        sort(temp->begin(), temp->end());
        int start = temp->size(), end = 0;
        for (int i = 0; i < temp->size(); ++i) {
            if (temp->at(i) != nums.at(i)) {
                start = min(start, i);
                end = max(end, i);
            }
        }
        return (end - start >= 0 ? end - start + 1 : 0);
    }
};

int main () {
    auto arr = new vector<int>{3,2,1};
    cout << Solution().findUnsortedSubarray(*arr) << endl;
}