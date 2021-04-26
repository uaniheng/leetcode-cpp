//
// Created by gyc on 2021/4/26.
//
#include "../../common_c.h"

int shipWithinDays(int *weights, int weightsSize, int D) {
    int left = 0, right = 0;
    for (int i = 0; i < weightsSize; ++i) {
        left = fmax(left, weights[i]);
        right += weights[i];
    }
    while (left < right) {
        int mid = (left + right) / 2;
        int need = 1, cur = 0;
        for (int i = 0; i < weightsSize; ++i) {
            if (cur + weights[i] > mid) {
                ++need;
                cur = 0;
            }
            cur += weights[i];
        }
        if (need <= D) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("%d", shipWithinDays(arr, 10, 5));
}
