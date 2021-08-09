//
// Created by XinShuoWang on 2021/8/6.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "TreeNode.h"

TEST(tree_173, BFS) {
  using namespace std;
  class BSTIterator {
    vector<int> path_;
    int p_;

   public:
    BSTIterator(TreeNode* root) {
      p_ = 0;
      dfs(root);
    }

    void dfs(TreeNode* root) {
      if (root == nullptr) return;
      dfs(root->left);
      path_.push_back(root->val);
      dfs(root->right);
    }

    int next() { return path_[p_++]; }

    bool hasNext() { return p_ < path_.size(); }
  };
}