//
// Created by XinShuo Wang on 2021/9/4 9:15
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_78, 1) {
  using namespace std;
  class Solution {
    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> visited;

   public:
    vector<vector<int>> subsets(vector<int>& nums) {
      visited.resize(nums.size(), false);
      ans.emplace_back();
      for (int& num : nums) {
        ans.emplace_back(vector<int>{num});
      }
      if (nums.size() != 1) ans.push_back(nums);
      for (int i = 2; i < nums.size(); ++i) {
        work(nums, 0, 0, i);
      }
      return ans;
    }

    void work(vector<int>& nums, int start, int count, int len) {
      if (count == len) {
        ans.push_back(path);
        return;
      }
      for (int i = start; i < nums.size(); ++i) {
        if (!visited[i]) {
          visited[i] = true;
          path.push_back(nums[i]);
          work(nums, i + 1, count + 1, len);
          path.pop_back();
          visited[i] = false;
        }
      }
    }
  };
}

TEST(leetcode_78, 2) {
  using namespace std;
  class Solution {
   public:
    vector<vector<int>> subsets(vector<int>& nums) {
      int size = pow(2, nums.size()) - 1;
      vector<vector<int>> ans;
      for (int i = 0; i < size; ++i) {
        vector<int> path;
        int count = 0;
        while ((i >> count) != 0) {
          if (((i >> count) & 1) != 0) path.push_back(nums[count]);
          count++;
        }
        ans.emplace_back(path);
      }
      return ans;
    }
  };
}