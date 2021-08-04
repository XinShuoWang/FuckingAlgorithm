//
// Created by xinsh on 2021/8/4.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(dp_53, 1) {
    using namespace std;
    class Solution {
    public:
        int maxSubArray(vector<int> &nums) {
            int max = INT_MIN;
            for (int i = 0; i < nums.size(); ++i) {
                for (int j = 1; j <= nums.size() - i; ++j) {
                    int v = sum(nums, i, j);
                    max = max < v ? v : max;
                }
            }
            return max;
        }

        int sum(vector<int> &nums, int start, int len) {
            int v = 0;
            for (int i = start; i < start + len; ++i) {
                v += nums[i];
            }
            return v;
        }
    };
}

TEST(dp_53, 2) {
    using namespace std;
    class Solution {
    public:
        int maxSubArray(vector<int> &nums) {
            int max = INT_MIN;
            for (int i = 0; i < nums.size(); ++i) {
                int t = nums[i];
                max = max < t ? t : max;
                for (int j = i + 1; j < nums.size(); ++j) {
                    t += nums[j];
                    max = max < t ? t : max;
                }
            }
            return max;
        }
    };
}
