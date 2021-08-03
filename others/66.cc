//
// Created by xinsh on 2021/8/3.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(othres_66, 1) {
    using namespace std;
    class Solution {
    public:
        vector<int> plusOne(vector<int> &digits) {
            vector<int> res;
            int cf = 1;
            while (!digits.empty()) {
                int value = digits[digits.size() - 1];
                value += cf;
                if (value >= 10) {
                    cf = 1;
                    res.insert(res.begin(), value - 10);
                } else {
                    cf = 0;
                    res.insert(res.begin(), value);
                }
                digits.pop_back();
            }
            if (cf == 1) res.insert(res.begin(), cf);
            return res;
        }
    };

    Solution solution;
    vector<int> v = {9, 9, 0};
    vector<int> r = solution.plusOne(v);
    for (int a:r) {
        cout << a;
    }
}
