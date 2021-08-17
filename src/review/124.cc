//
// Created by XinShuoWang on 2021/8/10.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "TreeNode.h"

TEST(tree_124, DFS) {
  using namespace std;
  class Solution {
    int val;

   public:
    Solution() { val = INT_MIN; }

    int maxPathSum(TreeNode* root) {
      int v = dfs(root);
      val = val > v ? val : v;
      return val;
    }

    int dfs(TreeNode* root) {
      if (root == nullptr) return 0;
      int left = dfs(root->left);
      int right = dfs(root->right);
      int t = root->val + max(left, right);
      val = val > t ? val : t;
      return t;
    }
  };
}