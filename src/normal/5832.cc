//
// Created by XinShuo Wang on 2021/8/15 11:03
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_5832, 1) {
  using namespace std;
  class Solution {
   public:
    vector<int> rearrangeArray(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      int start1 = 0, start2 = nums.size() / 2.0, t = start2;
      vector<int> res;
      if (start1 % 2 == 0) {
        for (int i = 0; i < nums.size() / 2 + 1; ++i) {
          if (start2 < nums.size()) res.push_back(nums[start2++]);
          if (start1 < t) res.push_back(nums[start1++]);
        }
      } else {
        for (int i = 0; i < nums.size() / 2 + 1; ++i) {
          if (start1 < t) res.push_back(nums[start1++]);
          if (start2 < nums.size()) res.push_back(nums[start2++]);
        }
      }
      return res;
    }
  };
}