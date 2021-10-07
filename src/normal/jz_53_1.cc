//
// Created by XinShuo Wang on 2021/10/6 10:29
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_jz_53_1, 1) {
  using namespace std;
  class Solution {
   public:
    int search(vector<int>& nums, int target) {
      int ans = 0;
      for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == target) {
          for (int j = i; j < nums.size(); ++j) {
            if (nums[j] == target) ans++;
          }
          return ans;
        }
      }
      return 0;
    }
  };
}