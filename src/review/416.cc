//
// Created by XinShuo Wang on 2021/10/10 20:58
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_416, 1) {
  using namespace std;
  class Solution {
    unordered_map<uint64_t, bool> cache;
    unordered_map<uint64_t, bool>::iterator it;

    uint64_t get(int idx, int left, int right) {
      uint64_t ans = idx;
      ans <<= 8;
      ans += left;
      ans <<= 28;
      ans += right;
      return ans;
    }

   public:
    bool canPartition(vector<int>& nums) { return work(nums, 0, 0, 0); }

    bool work(vector<int>& nums, int idx, int left, int right) {
      if (idx >= nums.size()) {
        if (left == right) return true;
        return false;
      }
      if ((it = cache.find(get(idx, left, right))) != cache.end())
        return it->second;
      bool ans = work(nums, idx + 1, left + nums[idx], right);
      ans |= work(nums, idx + 1, left, right + nums[idx]);
      cache[get(idx, left, right)] = ans;
      return ans;
    }
  };
}