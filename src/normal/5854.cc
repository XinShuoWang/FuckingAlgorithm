//
// Created by XinShuo Wang on 2021/8/29 15:48
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_5854, 1) {
  using namespace std;
  class Solution {
   public:
    int minimumDifference(vector<int>& nums, int k) {
      if (nums.size() == 1) return 0;
      sort(nums.begin(), nums.end());
      int ans = INT_MAX;
      k--;
      for (int i = 0; i < nums.size() - k; ++i) {
        ans = min(ans, nums[i + k] - nums[i]);
      }
      return ans;
    }
  };
}