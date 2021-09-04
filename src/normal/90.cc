//
// Created by XinShuo Wang on 2021/9/4 10:04
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_90, 1) {
  using namespace std;
  class Solution {
    set<vector<int>> s;
    vector<int> path;
    vector<bool> visited;

   public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      visited.resize(nums.size(), false);
      //
      sort(nums.begin(), nums.end());
      s.insert(vector<int>{});
      for (int num : nums) {
        s.insert(vector<int>{num});
      }
      if (nums.size() != 1) s.insert(nums);
      for (int i = 2; i < nums.size(); ++i) {
        work(nums, 0, 0, i);
      }
      // return
      vector<vector<int>> ans;
      for (const vector<int>& v : s) {
        ans.push_back(v);
      }
      return ans;
    }

    void work(vector<int>& nums, int start, int count, int len) {
      if (count == len) {
        s.insert(path);
        // for(int p : path) cout << p << ",";
        // cout << endl;
        return;
      }
      for (int i = start; i < nums.size(); ++i) {
        if (!visited[i]) {
          visited[i] = true;
          path.push_back(nums[i]);
          // 这里千万要注意是i+1而不是start+1，否则会走回头路
          work(nums, i + 1, count + 1, len);
          path.pop_back();
          visited[i] = false;
        }
      }
    }
  };

  Solution solution;
  vector<int> v{4, 5, 10};
  solution.subsetsWithDup(v);
}