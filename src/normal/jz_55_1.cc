//
// Created by XinShuo Wang on 2021/10/21 12:53
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "TreeNode.h"

TEST(leetcode_jz_55_1, 1) {
  using namespace std;
  class Solution {
   public:
    int maxDepth(TreeNode* root) {
      if (root == nullptr) return 0;
      return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
  };
}