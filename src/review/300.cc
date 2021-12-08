//
// Created by XinShuo Wang on 2021/9/11 12:49
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_300, 1) {
  using namespace std;
  class Solution {
    int ans = 1;
    vector<int> path;

   public:
    int lengthOfLIS(vector<int>& nums) {
      work(nums, 0);
      return ans;
    }

    void work(vector<int>& nums, int pos) {
      if (pos >= nums.size()) {
        ans = max(ans, (int)path.size());
        return;
      }
      if (path.empty()) {
        path.push_back(nums[pos]);
        work(nums, pos + 1);
        path.pop_back();
      } else {
        if (nums[pos] > path.back()) {
          path.push_back(nums[pos]);
          work(nums, pos + 1);
          path.pop_back();
        }
      }
      work(nums, pos + 1);
    }
  };
}

TEST(leetcode_300, 2) {
  using namespace std;
  class Solution {
    unordered_map<int, int> cache;
    unordered_map<int, int>::iterator it;
    vector<int> path;

   public:
    int lengthOfLIS(vector<int>& nums) {
      path.push_back(INT_MIN);
      return work(nums, 0);
    }

    int work(vector<int>& nums, int pos) {
      if ((it = cache.find(pos)) != cache.end()) return it->second;
      if (pos >= nums.size()) return 0;
      int ans = INT_MIN;
      // 这个判断可以保证递增
      if (nums[pos] > path.back()) {
        path.push_back(nums[pos]);
        ans = max(ans, work(nums, pos + 1) + 1);
        path.pop_back();
      }
      ans = max(ans, work(nums, pos + 1));
      cache[pos] = ans;
      return ans;
    }
  };
}

TEST(leetcode_300, 3) {
  using namespace std;
  class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
      vector<int> v(nums.size(), 1);
      int ans = INT_MIN;
      for (int i = 0; i < nums.size(); ++i) {
        for (int j = 0; j < i; ++j) {
          if (v[i] > v[j]) v[i] = max(v[i], v[j] + 1);
          ans = max(ans, v[i]);
        }
      }
      return ans;
    }
  };
}