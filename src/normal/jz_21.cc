//
// Created by XinShuo Wang on 2021/10/19 13:16
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_jz_21, 1) {
  using namespace std;
  class Solution {
   public:
    vector<int> exchange(vector<int>& nums) {
      int i = 0, size = nums.size(), j = size - 1;
      while (i < j) {
        while (i < size && nums[i] % 2 == 1) ++i;
        while (j >= 0 && nums[j] % 2 == 0) --j;
        if (i < size && j >= 0 && i < j) {
          swap(nums[i], nums[j]);
          //i++, j--;
        }
      }
      return nums;
    }
  };
}