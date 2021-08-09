//
// Created by xinsh on 2021/8/4.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "TreeNode.h"

TEST(tree_235, 1) {
  using namespace std;
  class Solution {
   public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      if (p == q) return p;
      if (p->left == q || p->right == q) return p;
      if (q->left == p || q->right == p) return q;
      if (p->val > q->val) {
        return work(root, p, q);
      } else {
        return work(root, q, p);
      }
    }

    // 可以保证p->val > q->val
    TreeNode* work(TreeNode* root, TreeNode* p, TreeNode* q) {
      // 不会同时取到等于，这是边界情况
      if (root->val <= p->val && root->val >= q->val) return root;
      if (root->val < q->val) {
        return lowestCommonAncestor(root->right, p, q);
      }
      if (root->val > p->val) {
        return lowestCommonAncestor(root->left, p, q);
      }
      return nullptr;
    }
  };
}
