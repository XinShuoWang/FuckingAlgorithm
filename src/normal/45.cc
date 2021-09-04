//
// Created by XinShuo Wang on 2021/9/2 13:34
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_45, 1) {
  using namespace std;
  class Solution {
   public:
    int jump(vector<int>& nums) {
      int ans = work(nums, 0, 0);
      return ans;
    }

    int work(vector<int>& nums, int pos, int step) {
      if (pos >= nums.size() - 1) {
        return step;
      }
      int ans = INT_MAX;
      for (int i = 1; i <= nums[pos]; ++i) {
        ans = min(ans, work(nums, pos + i, step + 1));
      }
      return ans;
    }
  };

  Solution solution;
  vector<int> v{2, 3, 1, 1, 4};
  solution.jump(v);
}

TEST(leetcode_45, 2) {
  using namespace std;
  class Solution {
    unordered_map<int, int> m;

   public:
    int jump(vector<int>& nums) {
      int ans = work(nums, 0);
      return ans;
    }

    int work(vector<int>& nums, int pos) {
      if (pos >= nums.size() - 1) {
        return 0;
      }
      if (m.find(pos) != m.end()) return m[pos];
      int ans = INT_MAX;
      for (int i = 1; i <= nums[pos]; ++i) {
        ans = min(ans, work(nums, pos + i));
      }
      if (ans != INT_MAX) ans++;
      m[pos] = ans;
      return ans;
    }
  };

  Solution solution;
  vector<int> v{2, 3, 1, 1, 4};
  solution.jump(v);
}