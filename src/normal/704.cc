//
// Created by XinShuo Wang on 2021/8/14 20:18
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_704, 1) {
  using namespace std;
  class Solution {
   public:
    int search(vector<int>& nums, int target) {
      int left = 0, right = nums.size();
      while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;
        if (nums[mid] < target) {
          left = mid + 1;
        } else {
          right = mid;
        }
      }
      return -1;
    }
  };
}