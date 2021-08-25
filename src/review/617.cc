//
// Created by XinShuo Wang on 2021/8/25 10:05
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "TreeNode.h"

TEST(leetcode_617, 1) {
  using namespace std;
  class Solution {
   public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
      if (root1 != nullptr && root2 != nullptr) {
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
      } else if (root1 != nullptr && root2 == nullptr) {
        return root1;
      } else if (root1 == nullptr && root2 != nullptr) {
        return root2;
      }
      return nullptr;
    }
  };
}