//
// Created by XinShuo Wang on 2021/8/14 22:19
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_53, 1) {
  using namespace std;
  class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
      int res = INT_MIN;
      for (int i = 0; i < nums.size(); ++i) {
        int val = nums[i];
        res = max(res, val);
        for (int j = i + 1; j < nums.size(); ++j) {
          val += nums[j];
          res = max(res, val);
        }
      }
      return res;
    }
  };
}