//
// Created by XinShuoWang on 2021/8/9.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "TreeNode.h"

TEST(tree_129, DFS) {
  using namespace std;
  class Solution {
    vector<int> sum_;
    vector<int> path_;

    int sum() {
      int i;
      for (i = 0; i < path_.size(); ++i) {
        if (path_[i] != 0) break;
      }
      int res = 0;
      for (; i < path_.size(); ++i) {
        res *= 10;
        res += path_[i];
      }
      return res;
    }

   public:
    int sumNumbers(TreeNode* root) {
      work(root);
      int v = 0;
      for (int i = 0; i < sum_.size(); ++i) {
        v += sum_[i];
      }
      return v;
    }

    void work(TreeNode* root) {
      if (root == nullptr) return;
      if (root->left == nullptr && root->right == nullptr) {
        path_.push_back(root->val);
        sum_.push_back(sum());
        path_.pop_back();
        return;
      }
      path_.push_back(root->val);
      work(root->left);
      work(root->right);
      path_.pop_back();
    }
  };
}