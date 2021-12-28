//
// Created by XinShuo Wang on 2021/12/23 11:58
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "ListNode.h"
#include "TreeNode.h"

TEST(leetcode_448, 1) {
  using namespace std;
  class Solution {
   public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
      const int n = nums.size();
      unordered_set<int> s;
      s.reserve(n);
      for (int i = 1; i <= n; ++i) s.insert(i);
      for (int i = 0; i < n; ++i) s.erase(nums[i]);
      vector<int> ans;
      ans.reserve(s.size());
      for (auto v : s) {
        ans.push_back(v);
      }
      return ans;
    }
  };
}

TEST(leetcode_448, 2) {
  using namespace std;
  class Solution {
   public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
      const int n = nums.size(), v = 200000;
      for (int i = 0; i < n; ++i) {
        if (nums[i] > v)
          nums[nums[i] - v - 1] += v;
        else
          nums[nums[i] - 1] += v;
      }
      vector<int> ans;
      for (int i = 0; i < n; ++i) {
        if (nums[i] < v) ans.push_back(i);
      }
      return ans;
    }
  };
}