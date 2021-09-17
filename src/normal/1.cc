//
// Created by XinShuo Wang on 2021/9/14 12:06
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_1, 1) {
  using namespace std;
  class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int, int> m;
      unordered_map<int, int>::iterator it;
      for (int i = 0; i < nums.size(); ++i) {
        if ((it = m.find(target - nums[i])) != m.end())
          return vector<int>{it->second, i};
        else
          m[nums[i]] = i;
      }
      return vector<int>{};
    }
  };
}