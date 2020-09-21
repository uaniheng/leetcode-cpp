//
// Created by gyc on 2020/9/21.
//
#include "../../common.h"
#include <unordered_set>



class Solution {
private:


    string upState(string state, int index) {
        if (state[index] == '9'){
            state[index] = '0';
        } else {
            state[index] ++;
        }
        return state;
    }

    string downState(string state, int index) {

        if (state[index] == '0'){
            state[index] = '9';
        }else {
            state[index] --;
        }
        return state;
    }
public:
    int openLock(vector<string>& deadends, string target) {
        set<string> visited;

        visited.insert(deadends.begin(), deadends.end());
        if (visited.count("0000")) return -1;

        int num = 0;

        queue<string> que{};
        que.push("0000");
        visited.insert("0000");

        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i ++) {
                string state = que.front();
                que.pop();

                if (state == target) {
                    return num;
                }

                for(int j = 0; j < 4; j ++) {
                    string up = upState(state, j);
                    string down = downState(state, j);
                    if (!visited.count(up)) {
                        visited.insert(up);
                        que.push(up);
                    }
                    if (!visited.count(down)) {
                        visited.insert(down);
                        que.push(down);
                    }
                }
            }
            num ++;
        }
        return -1;
    }
};

int main() {
    // ["0201","0101","0102","1212","2002"]
    //"0202"

    vector<string> deadends{"0201","0101","0102","1212","2002"};

    cout << Solution().openLock(deadends, "0202") << endl;
}