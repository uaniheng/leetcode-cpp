//
// Created by GYC on 2021/5/20.
//
#include "../../common.h"

class MinStack {
private:
    vector<int> vec;
    stack<int> minIndex;

public:
    /** initialize your data structure here. */
    MinStack() {
        vec = vector<int>();
        minIndex = stack<int>();
    }

    void push(int val) {
        if (vec.empty() || val < getMin()) {
            minIndex.push(vec.size());
        }
        vec.emplace_back(val);
    }

    void pop() {
        if (vec.empty()){
            return;
        }
        vec.pop_back();
        if (vec.size() == minIndex.top()) {
            minIndex.pop();
        }
    }

    int top() {
        return vec.back();
    }

    int getMin() {
        return vec[minIndex.top()];
    }
};
