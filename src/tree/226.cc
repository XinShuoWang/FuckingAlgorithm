//
// Created by xinsh on 2021/8/4.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "TreeNode.h"

TEST(tree_226, 1) {
  using namespace std;
  class Solution {
   public:
    TreeNode* invertTree(TreeNode* root) {
      if (root == nullptr) return root;
      TreeNode* temp = root->right;
      root->right = root->left;
      root->left = temp;
      invertTree(root->left);
      invertTree(root->right);
      return root;
    }
  };
}
