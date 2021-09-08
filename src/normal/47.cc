//
// Created by XinShuo Wang on 2021/9/5 9:13
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_47, 1) {
  using namespace std;
  class Solution {
    set<vector<int>> s;
    vector<int> path;
    vector<bool> visited;

   public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
      visited.resize(nums.size(), false);
      sort(nums.begin(), nums.end());
      work(nums);
      vector<vector<int>> ans;
      for (const vector<int>& v : s) {
        ans.emplace_back(v);
      }
      return ans;
    }

    void work(vector<int>& nums) {
      if (path.size() == nums.size()) {
        s.insert(path);
        return;
      }
      for (int i = 0; i < nums.size(); ++i) {
        if (!visited[i]) {
          visited[i] = true;
          path.push_back(nums[i]);
          work(nums);
          path.pop_back();
          visited[i] = false;
        }
      }
    }
  };
}

TEST(leetcode_47, 2) {
  using namespace std;
  class Solution {
   public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
      vector<vector<int>> ans;
      sort(nums.begin(), nums.end());
      do {
        ans.emplace_back(nums);
      } while (next_permutation(begin(nums), end(nums)));
      return ans;
    }
  };
}