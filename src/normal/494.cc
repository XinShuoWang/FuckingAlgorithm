//
// Created by XinShuo Wang on 2021/10/10 16:54
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_494, 1) {
  using namespace std;
  class Solution {
    int ans = 0;

   public:
    int findTargetSumWays(vector<int>& nums, int target) {
      work(nums, target, 0);
      return ans;
    }

    void work(vector<int>& nums, int target, int idx) {
      if (idx >= nums.size()) {
        if (target == 0) ans++;
        return;
      }
      work(nums, target + nums[idx], idx + 1);
      work(nums, target - nums[idx], idx + 1);
    }
  };
}

TEST(leetcode_494, 2) {
  using namespace std;
  class Solution {
    map<pair<int, int>, int> cache;
    map<pair<int, int>, int>::iterator it;

   public:
    int findTargetSumWays(vector<int>& nums, int target) {
      return work(nums, target, 0);
    }

    int work(vector<int>& nums, int target, int idx) {
      if (idx >= nums.size()) {
        if (target == 0) return 1;
        return 0;
      }
      if ((it = cache.find(make_pair(idx, target))) != cache.end())
        return it->second;
      int a = work(nums, target + nums[idx], idx + 1);
      int b = work(nums, target - nums[idx], idx + 1);
      cache[make_pair(idx, target)] = a + b;
      return a + b;
    }
  };
}