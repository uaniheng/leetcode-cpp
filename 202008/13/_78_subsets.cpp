//
// Created by gyc on 2020/8/13.
//
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        auto result = new vector<vector<int>>;
        result->push_back(*(new vector<int>));

        for (int num: nums) {
            auto newSubsets = new vector<vector<int>>;
            for (const auto& curr: *result) {
                auto n = new vector<int>(curr);
                n->push_back(num);
                newSubsets->push_back(*n);
            }
            for(const vector<int>& curr: *newSubsets) {
                result->push_back(curr);
            }
        }
        return *result;
    }
};

int main() {


}