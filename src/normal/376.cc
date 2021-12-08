//
// Created by XinShuo Wang on 2021/12/3 15:05
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_376, 1) {
  using namespace std;
  class Solution {
    int ans;
    vector<int> path;

   public:
    Solution() { ans = 0; }

    bool ok() {
      switch (path.size()) {
        case 0:
          return false;
        case 1:
          return true;
        case 2:
          return path[1] != path[0];
        default:
          if (path[1] == path[0]) return false;
          bool flag = path[1] - path[0] > 0;
          for (int i = 2; i < path.size(); ++i) {
            if (path[i] == path[i - 1]) return false;
            if (flag == (path[i] - path[i - 1] > 0)) return false;
            flag = !flag;
          }
          return true;
      }
    }

    void dfs(vector<int>& nums, int idx) {
      if (idx >= nums.size()) {
        if (ok()) {
          ans = max(ans, (int)path.size());
        }
        return;
      }
      path.push_back(nums[idx]);
      dfs(nums, idx + 1);
      path.pop_back();
      dfs(nums, idx + 1);
    }

    int wiggleMaxLength(vector<int>& nums) {
      dfs(nums, 0);
      return ans;
    }
  };
}

TEST(leetcode_376, 2) {
  using namespace std;
  class Solution {
    int ans;
    vector<int> path;

   public:
    Solution() { ans = 0; }

    void dfs(vector<int>& nums, int want, int idx) {
      if (idx >= nums.size()) {
        ans = max(ans, (int)path.size());
        return;
      }
      if (path.empty()) {
        path.push_back(nums[idx]);
        dfs(nums, want, idx + 1);
        path.pop_back();
      } else if ((nums[idx] - path.back()) * want > 0) {
        path.push_back(nums[idx]);
        dfs(nums, -want, idx + 1);
        path.pop_back();
      }
      dfs(nums, want, idx + 1);
    }

    int wiggleMaxLength(vector<int>& nums) {
      dfs(nums, 1, 0);
      dfs(nums, -1, 0);
      return ans;
    }
  };
}

TEST(leetcode_376, 3) {
  using namespace std;
  class Solution {
    unordered_map<int64_t, int> cache;
    unordered_map<int64_t, int>::iterator it;

   public:
    int64_t combine(int idx, int want, int pre) {
      int64_t ans = idx;
      ans <<= 16;
      ans += (want == -1 ? 2 : 3);
      ans <<= 16;
      ans += pre;
      return ans;
    }

    int dfs(vector<int>& nums, int idx, int want, int pre) {
      if (idx >= nums.size()) return 0;
      if ((it = cache.find(combine(idx, want, pre))) != cache.end())
        return it->second;
      int ans = 0;
      if (pre == INT_MAX) {
        ans = max(ans, dfs(nums, idx + 1, want, nums[idx]) + 1);
      } else if ((nums[idx] - pre) * want > 0) {
        ans = max(ans, dfs(nums, idx + 1, -want, nums[idx]) + 1);
      }
      ans = max(ans, dfs(nums, idx + 1, want, pre));
      cache[combine(idx, want, pre)] = ans;
      return ans;
    }

    int wiggleMaxLength(vector<int>& nums) {
      return max(dfs(nums, 0, 1, INT_MAX), dfs(nums, 0, -1, INT_MAX));
    }
  };
}
