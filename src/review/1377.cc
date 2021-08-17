//
// Created by XinShuoWang on 2021/8/11.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(tree_1377, 1) {
  using namespace std;
  class Solution {
   public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
      map<int, vector<int>> m;
      vector<int> v;
      for (int i = 0; i < edges.size(); ++i) {
        if (m.count(edges[i][0]) == 0) {
          m[edges[i][0]] = vector<int>{edges[i][1]};
        } else {
          m[edges[i][0]].push_back(edges[i][1]);
        }
        if (m.count(edges[i][1]) == 0) {
          m[edges[i][1]] = vector<int>{edges[i][0]};
        } else {
          m[edges[i][1]].push_back(edges[i][0]);
        }
      }
      vector<bool> visited(n + 1, false);
      visited[edges[0][0]] = true;
      return dfs(m, visited, target, edges[0][0], t, 1);
    }

    double dfs(map<int, vector<int>>& m, vector<bool>& visited, int target,
               int pos, int t, double p) {
      if (pos == target) return p;
      if (m.count(pos) == 0) return 0;
      double res = 0.;
      int count = 0;
      for (int i = 0; i < m[pos].size(); ++i) {
        if(!visited[m[pos][i]]) count++;
      }
      for (int v : m[pos]) {
        if (!visited[v]) {
          visited[v] = true;
          res = max(res, dfs(m, visited, target, v, t - 1, p / count));
          visited[v] = false;
        }
      }
      return res;
    }
  };
}