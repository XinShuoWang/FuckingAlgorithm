//
// Created by XinShuo Wang on 2021/12/10 15:10
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_456, 1) {
  using namespace std;
  class Solution {
   public:
    bool find132pattern(vector<int>& nums) {
      const int n = nums.size();
      for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
          for (int k = j + 1; k < n; ++k) {
            if (nums[i] < nums[k] && nums[k] < nums[j]) return true;
          }
        }
      }
      return false;
    }
  };
}

TEST(leetcode_456, 2) {
  using namespace std;
  class Solution {
   public:
    bool find132pattern(vector<int>& nums) {
      const int n = nums.size();
      if (n < 3) return false;
      // 使用的是贪心算法
      int left = nums[0];
      multiset<int> right;
      for (int i = 2; i < n; ++i) right.insert(nums[i]);
      for (int i = 1; i < n - 1; ++i) {
        if (left < nums[i]) {
          // lower_bound:返回第一个大于或等于给定值的元素
          // upper_bound:返回第一个大于给定值的元素
          auto it = right.upper_bound(left);
          //cout << *it << endl;
          if (it != right.end() && *it < nums[i]) return true;
        }
        left = min(left, nums[i]);
        // 这里不能直接erase值，否则所有的值都会消失
        right.erase(right.find(nums[i + 1]));
      }
      return false;
    }
  };
}
