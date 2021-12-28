//
// Created by XinShuo Wang on 2021/12/15 12:44
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_851, 1) {
  using namespace std;
  class Solution {
    map<int, int> cache;
    map<int, int>::iterator it;
   public:
    int bfs(map<int, vector<int>>& m, vector<int>& quiet, int person) {
      queue<int> q;
      q.push(person);
      int db = quiet[person], idx = person;
      while (!q.empty()) {
        int head = q.front();
        q.pop();
        if((it=cache.find(head)) != cache.end()) {
          if(db > quiet[it->second]) {
            idx = it->second;
            db = quiet[idx];
          }
          // 无论大于、小于都要continue
          // 因为大于的话就找到值了没必要往下找
          // 小于的话这个分支肯定没用，要提前剪枝
          continue;
        }
        for (auto v : m[head]) {
          if (db > quiet[v]) {
            idx = v;
            db = quiet[v];
          }
          q.push(v);
        }
      }
      cache[person] = idx;
      return idx;
    }

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
      const int n = quiet.size();
      map<int, vector<int>> m;
      for (int i = 0; i < richer.size(); ++i) {
        if (m.find(richer[i][1]) == m.end()) {
          m[richer[i][1]] = vector<int>{richer[i][0]};
        } else {
          m[richer[i][1]].push_back(richer[i][0]);
        }
      }
      vector<int> ans(n, 0);
      for (int i = 0; i < n; ++i) {
        ans[i] = bfs(m, quiet, i);
      }
      return ans;
    }
  };
}