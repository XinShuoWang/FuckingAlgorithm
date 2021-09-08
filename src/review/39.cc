//
// Created by XinShuo Wang on 2021/9/5 10:08
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_39, 1) {
  using namespace std;
  class Solution {
    vector<vector<int>> ans;
    vector<int> path;

   public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      work(candidates, target, 0);
      return ans;
    }

    void work(vector<int>& candidates, int target, int idx) {
      if (target == 0) {
        ans.push_back(path);
        return;
      }
      if (target < 0 || idx >= candidates.size()) return;
      // 不选择，直接跳过
      work(candidates, target, idx + 1);
      if (idx < candidates.size()) {
        path.push_back(candidates[idx]);
        work(candidates, target - candidates[idx], idx);
        path.pop_back();
      }
    }
  };

  Solution solution;
  vector<int> v{2, 3, 6, 7};
  solution.combinationSum(v, 7);
}