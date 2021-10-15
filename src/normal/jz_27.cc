//
// Created by XinShuo Wang on 2021/10/10 9:57
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "TreeNode.h"

TEST(leetcode_jz_27, 1) {
  using namespace std;
  class Solution {
   public:
    TreeNode* mirrorTree(TreeNode* root) {
      if (root == nullptr) return nullptr;
      auto ans = new TreeNode(root->val);
      ans->left = mirrorTree(root->right);
      ans->right = mirrorTree(root->left);
      return ans;
    }
  };
}