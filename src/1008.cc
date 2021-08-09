//
// Created by XinShuoWang on 2021/8/9.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "TreeNode.h"

TEST(tree_1008, 1) {
  using namespace std;
  class Solution {
   public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
      return work(preorder, 0, preorder.size() - 1);
    }

    TreeNode* work(vector<int>& preorder, int left, int right) {
      if (left <= right) {
        int val = preorder[left];
        auto n = new TreeNode(val);
        int i;
        for (i = left; i <= right; ++i) {
          if (preorder[i] > val) break;
        }
        n->left = work(preorder, left + 1, i - 1);
        n->right = work(preorder, i, right);
        return n;
      }
      return nullptr;
    }
  };
}