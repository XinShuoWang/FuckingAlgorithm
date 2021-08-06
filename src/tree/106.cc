//
// Created by XinShuoWang on 2021/8/6.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "TreeNode.h"

TEST(tree_106, 1) {
  using namespace std;
  class Solution {
   public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
      return work(inorder, postorder, 0, inorder.size() - 1, 0,
                  postorder.size() - 1);
    }

    TreeNode* work(vector<int>& inorder, vector<int>& postorder, int s1, int e1,
                   int s2, int e2) {
      if (s1 <= e1 && s2 <= e2) {
        auto tree_node = new TreeNode(postorder[e2]);
        int i;
        for (i = s1; i < e1; ++i) {
          if (inorder[i] == postorder[e2]) break;
        }
        // 像这种具体数字的细节可以代入栗子试一下，否则很容易多1或者少1
        tree_node->left =
            work(inorder, postorder, s1, i - 1, s2, s2 + (i - s1) - 1);
        tree_node->right =
            work(inorder, postorder, i + 1, e1, s2 + (i - s1), e2 - 1);
        return tree_node;
      }
      return nullptr;
    }
  };
}