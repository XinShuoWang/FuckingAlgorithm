//
// Created by XinShuo Wang on 2021/9/17 9:29
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_27, 1) {
  using namespace std;
  class Solution {
   public:
    int removeElement(vector<int>& nums, int val) {
      int len = nums.size();
      for (int i = 0; i < len;) {
        if (nums[i] == val) {
          for (int j = i + 1; j < len; ++j) {
            nums[j - 1] = nums[j];
          }
          len--;
          continue;
        }
        i++;
      }
      return len;
    }
  };
}

TEST(leetcode_27, 2) {
  using namespace std;
  class Solution {
   public:
    int removeElement(vector<int>& nums, int val) {
      int i = 0, j = 0, len = nums.size();
      while (j < len) {
        while (j < len && nums[j] == val) ++j;
        if (j < len) nums[i++] = nums[j++];
      }
      return i;
    }
  };
}