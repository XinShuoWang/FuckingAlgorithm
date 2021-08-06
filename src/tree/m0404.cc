//
// Created by xinsh on 2021/8/4.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "TreeNode.h"

TEST(tree_m0404, 1) {
  using namespace std;
  class Solution {
   public:
    bool isBalanced(TreeNode* root) {
      if (root == nullptr) return true;
      if (abs(depth(root->left) - depth(root->right)) > 1) return false;
      return isBalanced(root->left) && isBalanced(root->right);
    }

    int depth(TreeNode* root) {
      if (root == nullptr) return 0;
      return 1 + max(depth(root->left), depth(root->right));
    }
  };
}
