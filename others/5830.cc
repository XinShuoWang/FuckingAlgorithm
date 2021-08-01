//
// Created by xinsh on 2021/8/1.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(othres_5830, 1) {
    using namespace std;
    class Solution {
    public:
        bool isThree(int n) {
            if (n == 1 || n == 2 || n == 3) return false;
            int end = sqrt(n), flag = 0;
            for (int i = 2; i <= end; ++i) {
                if (n % i == 0) {
                    if (i == end) flag++;
                    else flag += 2;
                    if (flag >= 2)return false;
                }
            }
            return flag == 1;
        }
    };
}