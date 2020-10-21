//
// Created by gyc on 2020/10/21.
//
#include "../../common.h"

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0;

        while (j < typed.size()) {
            if (i < name.size() && name[i] == typed[j]) {
                i ++;
                j ++;
            }else if(j > 0 && typed[j] == typed[j - 1]) {
                j ++;
            }else {
                return false;
            }
        }
        return true;
    }
};

int main() {

    cout << Solution().isLongPressedName("saeed", "ssaaedd") << endl;

}