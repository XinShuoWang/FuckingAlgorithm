//
// Created by XinShuo Wang on 2021/9/3 10:27
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_797, 1) {
  using namespace std;
  class Solution {
    vector<vector<int>> ans;
    vector<int> path;

   public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
      path.push_back(0);
      work(graph, 0);
      return ans;
    }

    void work(vector<vector<int>>& graph, int pos) {
      if (pos == graph.size() - 1) {
        ans.push_back(path);
        return;
      }
      for (int i : graph[pos]) {
        path.push_back(i);
        work(graph, i);
        path.pop_back();
      }
    }
  };
}