//
// Created by XinShuoWang on 2021/8/6.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "TreeNode.h"

TEST(tree_199, BFS) {
  using namespace std;
  class Solution {
   public:
    vector<int> rightSideView(TreeNode* root) {
      if (root == nullptr) return vector<int>{};
      queue<TreeNode*> q;
      vector<int> res;
      q.push(root);
      while (!q.empty()) {
        int size = q.size();
        while (size > 0) {
          if (q.front()->left != nullptr) q.push(q.front()->left);
          if (q.front()->right != nullptr) q.push(q.front()->right);
          size--;
          if (size == 0) res.push_back(q.front()->val);
          q.pop();
        }
      }
      return res;
    }
  };
}