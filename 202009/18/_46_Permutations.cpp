//
// Created by gyc on 2020/9/18.
//
#include "../../common.h"

class Solution {

private:

    vector<vector<int>> res;

    bool contains(vector<int> &vec, int i) {
        for(int v: vec) {
            if (v == i){
                return true;
            }
        }
        return false;
    }


    void backTrack(vector<int> &seq, vector<int> &choice) {

        if (seq.size() == choice.size()) {
            res.push_back(seq);
            return;
        }

        for(int c: choice) {
            if (!contains(seq, c)) {
                seq.push_back(c);
                backTrack(seq, choice);
                seq.pop_back();
            }
        }
    }


public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> seq{};
        backTrack(seq, nums);
        return res;
    }
};

int main() {
    vector<int> vec{1,2,3};

    auto res = Solution().permute(vec);

    for(auto v: res) {
        for(auto i: v) {
            cout << i << ',';
        }
        cout << endl;
    }

}