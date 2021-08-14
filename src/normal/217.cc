//
// Created by XinShuo Wang on 2021/8/14 22:20
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_217, 1) {
  using namespace std;
  class Solution {
   public:
    bool containsDuplicate(vector<int>& nums) {
      set<int> s;
      for (int i = 0; i < nums.size(); ++i) {
        if (s.count(nums[i]) != 0) return true;
        s.insert(nums[i]);
      }
      return false;
    }
  };
}

TEST(leetcode_217, 2) {
  using namespace std;
  class Solution {
   public:
    bool containsDuplicate(vector<int>& nums) {
      if (nums.size() == 1) return false;
      sort(nums.begin(), nums.end(), greater<int>());
      int flag = nums[0];
      for (int i = 1; i < nums.size(); ++i) {
        if (flag == nums[i]) {
          return true;
        } else {
          flag = nums[i];
        }
      }
      return false;
    }
  };
}