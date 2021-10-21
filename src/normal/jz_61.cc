//
// Created by XinShuo Wang on 2021/10/19 14:05
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_jz_61, 1) {
  using namespace std;
  class Solution {
   public:
    bool isStraight(vector<int>& nums) {
      sort(nums.begin(), nums.end(), [](int a, int b) { return a < b; });
      int i = 0, j = 0;
      while (nums[i] == 0) ++i;
      j = i;
      int guess = nums[j];
      while (j < 5) {
        if (nums[j] == guess) {
          ++j, ++guess;
        } else {
          if (i > 0) {
            --i, ++guess;
          } else {
            return false;
          }
        }
      }
      return true;
    }
  };
}