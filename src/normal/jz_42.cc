//
// Created by XinShuo Wang on 2021/10/11 9:39
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_jz_42, 1) {
  using namespace std;
  class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
      vector<int> v(nums);
      int val = nums[0];
      for (int i = 1; i < nums.size(); ++i) {
        val += nums[i];
        v[i] = val;
      }
      int ans = nums[0];
      for (int i = 0; i < nums.size(); ++i) {
        ans = max(ans, v[i]);
        for (int j = i + 1; j < nums.size(); ++j) {
          ans = max(ans, v[j] - v[i]);
        }
      }
      return ans;
    }
  };
}

TEST(leetcode_jz_42, 2) {
  using namespace std;
  class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
      vector<int> v(nums);
      int ans = nums[0];
      for (int i = 1; i < nums.size(); ++i) {
        v[i] = v[i - 1] >= 0 ? v[i - 1] + nums[i] : nums[i];
        ans = max(ans, v[i]);
      }
      return ans;
    }
  };
}