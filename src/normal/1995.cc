//
// Created by XinShuo Wang on 2021/12/29 11:27
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "ListNode.h"
#include "TreeNode.h"

TEST(leetcode_1995, 1) {
  using namespace std;
  class Solution {
   public:
    int countQuadruplets(vector<int>& nums) {
      const int n = nums.size();
      int ans = 0;
      for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
          for (int k = j + 1; k < n; ++k) {
            for (int l = k + 1; l < n; ++l) {
              ans += (nums[i] + nums[j] + nums[k] == nums[l]);
            }
          }
        }
      }
      return ans;
    }
  };
}