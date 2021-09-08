//
// Created by XinShuo Wang on 2021/9/8 9:32
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_40, 1) {
  using namespace std;
  class Solution {
    set<vector<int>> s;
    vector<int> path;

   public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      sort(candidates.begin(), candidates.end());
      work(candidates, target, 0);
      return vector<vector<int>>{s.begin(), s.end()};
    }

    void work(vector<int>& candidates, int target, int idx) {
      if (target == 0) {
        s.insert(path);
        return;
      }
      if (target < 0 || idx >= candidates.size()) return;
      work(candidates, target, idx + 1);
      path.push_back(candidates[idx]);
      work(candidates, target - candidates[idx], idx + 1);
      path.pop_back();
    }
  };
}


TEST(leetcode_40, 2) {
  using namespace std;
  class Solution {
    set<vector<int>> s;
    vector<int> path;

   public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      sort(candidates.begin(), candidates.end());
      work(candidates, target, 0);
      return vector<vector<int>>{s.begin(), s.end()};
    }

    void work(vector<int>& candidates, int target, int idx) {
      if (target == 0) {
        s.insert(path);
        return;
      }
      if (target < 0 || idx >= candidates.size()) return;
      work(candidates, target, idx + 1);
      path.push_back(candidates[idx]);
      work(candidates, target - candidates[idx], idx + 1);
      path.pop_back();
    }
  };
}