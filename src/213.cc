//
// Created by XinShuo Wang on 2021/9/11 12:19
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_213, 1) {
  using namespace std;
  class Solution {
    int first = 0;
    map<pair<int, int>, int> cache;
    map<pair<int, int>, int>::iterator it;

   public:
    int rob(vector<int>& nums) { return work(nums, 0); }

    int work(vector<int>& nums, int pos) {
      if (pos >= nums.size()) return 0;
      if ((it = cache.find(make_pair(first, pos))) != cache.end())
        return it->second;
      if (pos == nums.size() - 1) {
        if (first) return 0;
        return nums[pos];
      }
      int ans = work(nums, pos + 1);
      if (pos == 0) first = 1;
      ans = max(ans, work(nums, pos + 2) + nums[pos]);
      cache[make_pair(first, pos)] = ans;
      return ans;
    }
  };

  Solution solution;
  vector<int> v{200, 3, 140, 20, 10};
  cout << solution.rob(v) << endl;
}