//
// Created by XinShuoWang on 2021/8/9.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "Node.h"

TEST(tree_429, BFS) {
  using namespace std;
  class Solution {
   public:
    vector<vector<int>> levelOrder(Node* root) {
      if (root == nullptr) return vector<vector<int>>{{}};
      queue<Node*> q;
      q.push(root);
      vector<vector<int>> res;
      while (!q.empty()) {
        int size = q.size();
        vector<int> t;
        while (size > 0) {
          t.push_back(q.front()->val);
          for (auto node : q.front()->children) {
            q.push(node);
          }
          q.pop();
          size--;
        }
        res.push_back(t);
      }
      return res;
    }
  };
}