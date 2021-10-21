//
// Created by XinShuo Wang on 2021/10/19 14:35
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_jz_57, 1) {
  using namespace std;
  class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_set<int> s;
      for (int num : nums) {
        if (s.find(target - num) != s.end())
          return vector<int>{num, target - num};
        else
          s.insert(num);
      }
      return vector<int>{};
    }
  };
}

TEST(leetcode_jz_57, 2) {
  using namespace std;
  class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
      int i = 0, j = nums.size() - 1;
      while (i < j) {
        int s = nums[i] + nums[j];
        if (s == target)
          return vector<int>{nums[i], nums[j]};
        else if (s < target)
          ++i;
        else
          --j;
      }
      return vector<int>{0, 0};
    }
  };
}