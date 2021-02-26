//
// Created by gyc on 2020/12/10.
//

#include "../../common.h"

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

        int five = 0, ten = 0;
        for(int i: bills) {
            if (i == 5) {
                ++five;
            } else if(i == 10) {
                if (five > 0) {
                    --five;
                    ++ten;
                } else{
                    return false;
                }
            } else {
                if (five&&ten != 0) {
                    --five;
                    --ten;
                }else if(five>=3){
                    five -= 3;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};