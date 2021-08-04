//
// Created by xinsh on 2021/8/4.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(dp_152, 1) {
    using namespace std;
    class Solution {
    public:
        int maxProduct(vector<int> &nums) {
            int max = INT_MIN;
            for (int i = 0; i < nums.size(); ++i) {
                int t = nums[i];
                max = max < t ? t : max;
                for (int j = i + 1; j < nums.size(); ++j) {
                    t *= nums[j];
                    max = max < t ? t : max;
                }
            }
            return max;
        }
    };
}
