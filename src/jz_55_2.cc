//
// Created by XinShuo Wang on 2021/10/21 13:16
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "TreeNode.h"

TEST(leetcode_jz_55_2, 1) {
  using namespace std;
  class Solution {
    int depth(TreeNode* root) {
      if (root == nullptr) return 0;
      return 1 + max(depth(root->left), depth(root->right));
    }

   public:
    bool isBalanced(TreeNode* root) {
      if(root== nullptr) return true;
      int left = depth(root->left);
      int right = depth(root->right);
      return abs(left - right) <= 1 && isBalanced(root->left) &&
             isBalanced(root->right);
    }
  };
}


TEST(leetcode_jz_55_2, 2) {
  using namespace std;
  class Solution {
   public:
    bool isBalanced(TreeNode* root) {
      if(root== nullptr)return true;
      bool a = isBalanced(root->left);
      bool b = isBalanced(root->right);

    }
  };
}