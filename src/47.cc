//
// Created by XinShuo Wang on 2021/8/13 18:36
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_47, 1) {
  using namespace std;
  class Solution {
    vector<int> path_;
    set<vector<int>> res_;
    vector<bool> visited_;

   public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
      visited_.resize(nums.size(), false);
      dfs(nums);
      vector<vector<int>> res;
      for (auto& v : res_) {
        res.push_back(v);
      }
      return res;
    }

    void dfs(vector<int>& nums) {
      if (all_of(visited_.begin(), visited_.end(),
                 [](bool flag) { return flag; })) {
        res_.insert(path_);
        return;
      }
      for (int i = 0; i < nums.size(); ++i) {
        if (!visited_[i]) {
          visited_[i] = true;
          path_.push_back(nums[i]);
          dfs(nums);
          path_.pop_back();
          visited_[i] = false;
        }
      }
    }
  };
}