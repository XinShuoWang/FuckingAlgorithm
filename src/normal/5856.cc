//
// Created by XinShuo Wang on 2021/8/29 15:51
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_5856, 1) {
  using namespace std;
  class Solution {
    vector<int> path, visited;
    int ans = INT_MAX;
    int st;

   public:
    void work() {
      int t = 0, s = 0;
      for (int i : path) {
        if (s + i > st) {
          t++;
          s = i;
        } else if (s + i == st) {
          t++;
          s = 0;
        } else {
          s += i;
        }
      }
      if (s != 0) t++;
      ans = min(ans, t);
    }

    void dfs(vector<int>& tasks) {
      for (int i = 0; i < tasks.size(); ++i) {
        if (!visited[i]) {
          visited[i] = true;
          path.push_back(tasks[i]);

          if (path.size() == tasks.size()) work();
          else dfs(tasks);

          path.pop_back();
          visited[i] = false;
        }
      }
    }

    int minSessions(vector<int>& tasks, int sessionTime) {
      visited.resize(tasks.size(), false);
      st = sessionTime;
      dfs(tasks);
      return ans;
    }
  };
}