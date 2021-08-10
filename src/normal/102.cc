//
// Created by xinsh on 2021/7/31.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "TreeNode.h"

TEST(tree_102, 102) {
  using namespace std;
  class Solution {
   public:
    vector<vector<int>> levelOrder(TreeNode* root) {
      vector<vector<int>> res;
      if (root == nullptr) return res;
      queue<TreeNode*> q;
      q.push(root);
      while (!q.empty()) {
        int size = q.size();
        vector<int> v;
        while (size > 0) {
          TreeNode* temp = q.front();
          v.push_back(temp->val);
          if (temp->left != nullptr) {
            q.push(temp->left);
          }
          if (temp->right != nullptr) {
            q.push(temp->right);
          }
          size--;
          q.pop();
        }
        res.push_back(v);
      }
      return res;
    }
  };
}
