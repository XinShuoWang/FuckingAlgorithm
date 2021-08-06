//
// Created by xinsh on 2021/7/30.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(disjoint_tree, 547) {
  using namespace std;
  class Solution {
    int n;
    int data[205];

   public:
    void init() {
      for (int i = 0; i < n; ++i) {
        data[i] = i;
      }
    }

    int find(int x) {
      // 注意此处是要去找父亲的父亲，data[x]存放的是父亲节点
      return x == data[x] ? x : (data[x] = find(data[x]));
    }

    void merge(int i, int j) { data[find(i)] = find(j); }

    int findCircleNum(vector<vector<int>>& isConnected) {
      n = isConnected.size();
      init();
      for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
          if (isConnected[i][j] == 1) {
            merge(i, j);
          }
        }
      }
      unordered_set<int> s;
      for (int i = 0; i < n; ++i) {
        s.insert(find(data[i]));
      }
      return s.size();
    }
  };

  vector<vector<int>> v;
  v.push_back(vector<int>{1, 0, 0, 1});
  v.push_back(vector<int>{0, 1, 1, 0});
  v.push_back(vector<int>{0, 1, 1, 1});
  v.push_back(vector<int>{1, 0, 1, 1});
  Solution solution;
  solution.findCircleNum(v);
}
