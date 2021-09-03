//
// Created by XinShuo Wang on 2021/9/2 9:50
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "TreeNode.h"

TEST(leetcode_572, 1) {
  using namespace std;
  class Solution {
   public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
      if (root == nullptr) return false;
      return work(root, subRoot) || isSubtree(root->left, subRoot) ||
             isSubtree(root->right, subRoot);
    }

    bool work(TreeNode* root, TreeNode* subRoot) {
      if (root != nullptr && subRoot != nullptr && root->val == subRoot->val) {
        return work(root->left, subRoot->left) &&
               work(root->right, subRoot->right);
      } else if (root == nullptr && subRoot == nullptr) {
        return true;
      }
      return false;
    }
  };
}