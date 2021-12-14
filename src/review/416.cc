//
// Created by XinShuo Wang on 2021/12/9 13:40
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_416, 1) {
  using namespace std;
  class Solution {
   public:
    bool dfs(vector<int>& nums, int step, int want) {
      if (want == 0 || step >= nums.size()) {
        if (want == 0) return true;
        return false;
      }
      bool ans = false;
      ans |= dfs(nums, step + 1, want - nums[step]);
      if (ans) return ans;
      ans |= dfs(nums, step + 1, want);
      return ans;
    }

    bool canPartition(vector<int>& nums) {
      int sum = accumulate(nums.begin(), nums.end(), 0);
      if (sum % 2 == 1) return false;
      return dfs(nums, 0, sum / 2);
    }
  };
}