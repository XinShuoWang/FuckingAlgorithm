//
// Created by XinShuo Wang on 2021/8/14 18:31
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_35, 1) {
  using namespace std;
  class Solution {
   public:
    int searchInsert(vector<int>& nums, int target) {
      int left = -1, right = nums.size();
      while (left < right) {
        int mid = left + (right - left) / 2;
        // cout << left << "," << right << "," << mid << endl;
        if (right - left == 1) return right;
        if (target == nums[mid]) return mid;
        if (target < nums[mid]) {
          right = mid;
        } else {
          left = mid;
        }
      }
      return 0;
    }
  };
}