//
// Created by XinShuo Wang on 2021/8/16 22:04
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_283, 1) {
  using namespace std;
  class Solution {
   public:
    void moveZeroes(vector<int>& nums) {
      int i = 0, j = 0;
      while (j < nums.size()) {
        while (j < nums.size() && nums[j] == 0) ++j;
        if (j < nums.size()) nums[i++] = nums[j++];
      }
      for (; i < nums.size(); ++i) {
        nums[i] = 0;
      }
    }
  };

  vector<int> v{0};
  Solution solution;
  solution.moveZeroes(v);
}

TEST(leetcode_283, 2) {
  using namespace std;
  class Solution {
   public:
    // 这里的算法是对上一种方法的改进，因为上一种方法
    // 的补0操作在[0,0,0,...,1]的时候会很消耗时间
    void moveZeroes(vector<int>& nums) {
      int i = 0, j = 0;
      while (j < nums.size()) {
        while (j < nums.size() && nums[j] == 0) ++j;
        if (j < nums.size()) {
          swap(nums[i], nums[j]);
          i++;
          j++;
        }
      }
    }
  };

  vector<int> v{0};
  Solution solution;
  solution.moveZeroes(v);
}