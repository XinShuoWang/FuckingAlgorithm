//
// Created by XinShuo Wang on 2021/9/11 11:44
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_198, 1) {
  using namespace std;
  class Solution {
   public:
    int rob(vector<int>& nums) {
      if (nums.empty()) {
        return 0;
      }
      int size = nums.size();
      if (size == 1) {
        return nums[0];
      }
      vector<int> dp = vector<int>(size, 0);
      dp[0] = nums[0];
      dp[1] = max(nums[0], nums[1]);
      for (int i = 2; i < size; i++) {
        dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
      }
      return dp[size - 1];
    }
  };
}

TEST(leetcode_198, 2) {
  using namespace std;
  class Solution {
    unordered_map<int, int> cache;
    unordered_map<int, int>::iterator it;

   public:
    int rob(vector<int>& nums) { return work(nums, 0); }

    int work(vector<int>& nums, int pos) {
      if ((it = cache.find(pos)) != cache.end()) return it->second;
      if (pos >= nums.size()) {
        return 0;
      }
      int a = work(nums, pos + 2) + nums[pos], b = work(nums, pos + 1);
      if (a > b) {
        cache[pos] = a;
        return a;
      } else {
        cache[pos] = b;
        return b;
      }
    }
  };

  vector<int> v{1, 2, 1, 1};
  Solution solution;
  solution.rob(v);
}