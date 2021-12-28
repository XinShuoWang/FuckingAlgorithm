//
// Created by XinShuo Wang on 2021/12/23 12:08
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "ListNode.h"
#include "TreeNode.h"

TEST(leetcode_437, 1) {
  using namespace std;
  class Solution {
   public:
    int dfs(TreeNode* root, int target, int val) {
      int ans = 0;
      if (val == target)
        ans += 1;
      if (root->left != nullptr)
        ans += dfs(root->left, target, val + root->left->val);
      if (root->right != nullptr)
        ans += dfs(root->right, target, val + root->right->val);
      return ans;
    }

    int pathSum(TreeNode* root, int targetSum) {
      if (root == nullptr) return 0;
      queue<TreeNode*> q;
      q.push(root);
      int ans = 0;
      while (!q.empty()) {
        auto node = q.front();
        q.pop();
        ans += dfs(node, targetSum, node->val);
        if (node->left != nullptr) q.push(node->left);
        if (node->right != nullptr) q.push(node->right);
      }
      return ans;
    }
  };
}