//
// Created by XinShuo Wang on 2021/10/10 9:58
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "TreeNode.h"

TEST(leetcode_jz_28, 1) {
  using namespace std;
  class Solution {
   public:
    bool isSymmetric(TreeNode* root) {
      if (root == nullptr) return true;
      return ok(root->left, root->right);
    }

    bool ok(TreeNode* left, TreeNode* right) {
      if (left == nullptr && right == nullptr) return true;
      if (left != nullptr && right == nullptr) return false;
      if (left == nullptr && right != nullptr) return false;
      if (left->val != right->val) return false;
      return ok(left->left, right->right) && ok(left->right, right->left);
    }
  };
}