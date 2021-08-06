//
// Created by XinShuoWang on 2021/8/6.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "TreeNode.h"

TEST(tree_105, 1) {
  using namespace std;
  class Solution {
   public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      return work(preorder, inorder, 0, preorder.size() - 1, 0,
                  inorder.size() - 1);
    }

    TreeNode* work(vector<int>& preorder, vector<int>& inorder, int s1, int e1,
                   int s2, int e2) {
      if (s1 <= e1 && s2 <= e2) {
        auto tree_node = new TreeNode(preorder[s1]);
        int i;
        for (i = s2; i < e2; ++i) {
          if (inorder[i] == preorder[s1]) break;
        }
        tree_node->left =
            work(preorder, inorder, s1 + 1, s1 + (i - s2), s2, i - 1);
        tree_node->right =
            work(preorder, inorder, s1 + (i - s2) + 1, e1, i + 1, e2);
        return tree_node;
      }
      return nullptr;
    }
  };
}