//
// Created by XinShuo Wang on 2021/9/9 16:57
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_413, 1) {
  using namespace std;
  class Solution {
    int get(int val) {
      if (val < 3)
        return 0;
      else {
        return (val - 2) * (val + 1) + 3 - val * (val + 1) / 2;
      }
    }

   public:
    int numberOfArithmeticSlices(vector<int>& nums) {
      if (nums.size() < 3) return 0;
      vector<int> v(nums.size(), 0);
      for (int i = 1; i < nums.size(); ++i) {
        v[i] = nums[i] - nums[i - 1];
      }
      int ans = 0;
      int start = 1, end = 1;
      while (end < nums.size()) {
        while (end < nums.size() && v[end] == v[start]) end++;
        ans += get(end - start + 1);
        start = end;
      }
      return ans;
    }
  };
}