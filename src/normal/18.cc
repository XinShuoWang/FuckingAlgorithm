//
// Created by XinShuo Wang on 2021/12/8 12:43
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_18, 1) {
  using namespace std;
  class Solution {
   public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
      const int n = nums.size();
      vector<vector<int>> ans;
      sort(nums.begin(), nums.end(), [](int a, int b) { return a < b; });
      for (int i = 0; i < n; ++i) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < n; ++j) {
          if (j > i + 1 && nums[j] == nums[j - 1]) continue;
          const int val = target - nums[i] - nums[j];
          int x = j + 1, y = n - 1;
          while (x < y) {
            if (x > j + 1 && nums[x] == nums[x - 1]) {
              x++;
              continue;
            }
            if (nums[x] + nums[y] == val) {
              ans.emplace_back(vector<int>{nums[i], nums[j], nums[x], nums[y]});
              x++, y--;
            } else if (nums[x] + nums[y] < val) {
              x++;
            } else {
              y--;
            }
          }
        }
      }
      return ans;
    }
  };
}