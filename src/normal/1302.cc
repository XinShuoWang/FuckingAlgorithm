//
// Created by XinShuoWang on 2021/8/9.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "TreeNode.h"

TEST(tree_1302, BFS) {
  using namespace std;
  class Solution {
   public:
    int deepestLeavesSum(TreeNode* root) {
      queue<TreeNode*> q;
      q.push(root);
      vector<int> res;
      while (!q.empty()) {
        int size = q.size();
        res.clear();
        while (size > 0) {
          res.push_back(q.front()->val);
          if (q.front()->left != nullptr) q.push(q.front()->left);
          if (q.front()->right != nullptr) q.push(q.front()->right);
          q.pop();
          size--;
        }
      }
      return accumulate(res.begin(), res.end(), 0);
    }
  };
}