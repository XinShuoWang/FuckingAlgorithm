//
// Created by xinsh on 2021/8/1.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(dp_55, 1) {
  using namespace std;
  class Solution {
   public:
    bool canJump(vector<int>& nums) {
      if (nums[0] == 0) {
        if (nums.size() == 1) return true;
        return false;
      }
      if (nums[0] >= nums.size()) return true;
      vector<bool> v(nums.size(), true);
      for (int i = 1; i <= nums[0]; ++i) {
        if (jump(nums, v, 0 + i)) return true;
      }
      return false;
    }

    bool jump(vector<int>& nums, vector<bool>& table, int pos) {
      if (nums.size() - 1 == pos) return true;
      if (!table[pos]) return false;
      for (int i = 1; i <= nums[pos]; ++i) {
        if (jump(nums, table, pos + i)) {
          return true;
        }
      }
      table[pos] = false;
      return false;
    }
  };
}
