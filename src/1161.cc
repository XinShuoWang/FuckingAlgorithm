//
// Created by XinShuoWang on 2021/8/9.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "TreeNode.h"

TEST(tree_1161, BFS) {
  using namespace std;
  class Solution {
   public:
    int maxLevelSum(TreeNode* root) {
      queue<TreeNode*> q;
      q.push(root);
      vector<int> res;
      while (!q.empty()) {
        int size = q.size();
        vector<int> t;
        while (size > 0) {
          t.push_back(q.front()->val);
          if (q.front()->left != nullptr) q.push(q.front()->left);
          if (q.front()->right != nullptr) q.push(q.front()->right);
          q.pop();
          size--;
        }
        res.push_back(accumulate(t.begin(), t.end(), 0));
      }
      int r = 0, v = INT_MIN;
      for (int i = 0; i < res.size(); ++i) {
        if (res[i] > v) {
          v = res[i];
          r = i;
        }
      }
      return r + 1;
    }
  };
}