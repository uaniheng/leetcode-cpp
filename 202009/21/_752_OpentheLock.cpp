//
// Created by gyc on 2020/9/21.
//
#include "../../common.h"

class Solution {
private:
    string upState(string state, int index) {
        if (state[index] == '9') {
            state[index] = '0';
        } else {
            state[index]++;
        }
        return state;
    }

    string downState(string state, int index) {

        if (state[index] == '0') {
            state[index] = '9';
        } else {
            state[index]--;
        }
        return state;
    }

public:
    int openLock(vector<string> &deadends, string target) {
        set<string> visited;
        visited.insert(deadends.begin(), deadends.end());
        if (visited.count("0000")) return -1;

        int num = 0;
        auto *q1 = new unordered_set<string>();
        auto *q2 = new unordered_set<string>();

        q1->emplace("0000");
        q2->emplace(target);

        visited.insert("0000");

        while (!q1->empty() && !q2->empty()) {

            auto *temp = new unordered_set<string>();

            for (const string &curr: *q1) {

                if (q2->count(curr)) {
                    return num;
                }
                visited.emplace(curr);
                for (int j = 0; j < 4; j++) {
                    string up = upState(curr, j);
                    string down = downState(curr, j);
                    if (!visited.count(up)) {
                        //visited.emplace(up);
                        temp->emplace(up);
                    }
                    if (!visited.count(down)) {
                        //visited.emplace(down);
                        temp->emplace(down);
                    }
                }
            }
            num++;
            q1 = q2;
            q2 = temp;
        }
        return -1;
    }
};

int main() {
    // ["0201","0101","0102","1212","2002"]
    //"0202"
    vector<string> deadends{};
    cout << Solution().openLock(deadends, "0202") << endl;
}