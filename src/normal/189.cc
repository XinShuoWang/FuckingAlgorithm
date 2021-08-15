//
// Created by XinShuo Wang on 2021/8/15 15:18
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_189, 1) {
  using namespace std;
  class Solution {
   public:
    void rotate(vector<int>& nums, int k) {
      vector<int> res(nums.size(), 0);
      for (int i = 0; i < nums.size(); ++i) {
        res[(i + k % nums.size()) % nums.size()] = nums[i];
      }
      nums = res;
    }
  };
}

TEST(leetcode_189, 2) {
  using namespace std;
  class Solution {
   public:
    void rotate(vector<int>& nums, int k) {
      reverse(nums.begin(), nums.end());
      reverse(nums.begin(), nums.begin() + k % nums.size());
      reverse(nums.begin() + k % nums.size(), nums.end());
    }
  };
}