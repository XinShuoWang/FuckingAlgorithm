//
// Created by XinShuo Wang on 2021/10/10 9:57
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "TreeNode.h"

TEST(leetcode_jz_26, 1) {
  using namespace std;
  class Solution {
   public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
      if (B == nullptr) return false;
      queue<TreeNode*> q;
      q.push(A);
      while (!q.empty()) {
        if (q.front()->val == B->val && same(q.front(), B)) return true;
        if (q.front()->left != nullptr) q.push(q.front()->left);
        if (q.front()->right != nullptr) q.push(q.front()->right);
        q.pop();
      }
      return false;
    }

    bool same(TreeNode* A, TreeNode* B) {
      if (B == nullptr) {
        return true;
      } else {
        if (A == nullptr) {
          return false;
        } else {
          return A->val == B->val && same(A->left, B->left) &&
                 same(A->right, B->right);
        }
      }
    }
  };
}