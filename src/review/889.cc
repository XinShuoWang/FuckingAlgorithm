//
// Created by XinShuoWang on 2021/8/9.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "TreeNode.h"

TEST(tree_889, 1) {
  using namespace std;
  class Solution {
   public:
    TreeNode* constructFromPrePost(vector<int>& preorder,
                                   vector<int>& postorder) {
      return work(preorder, postorder, 0, preorder.size() - 1, 0,
                  postorder.size() - 1);
    }

    TreeNode* work(vector<int>& preorder, vector<int>& postorder, int s1,
                   int e1, int s2, int e2) {
      // cout << "s1:" << s1 << ", e1:" << e1 << ", s2:" << s2 << ", e2:" << e2
      // << endl;
      if (s1 == e1) return new TreeNode(preorder[s1]);
      if (s2 == e2) return new TreeNode(postorder[s2]);
      if (s1 < e1 && s2 < e2) {
        auto it = find(postorder.begin() + s2, postorder.begin() + e2,
                       preorder[s1 + 1]);
        if (it != postorder.begin() + e2) {
          auto node = new TreeNode(preorder[s1]);
          int len = it - postorder.begin() - s2 + 1;
          node->left =
              //                                  1            3       0       2
              work(preorder, postorder, s1 + 1, s1 + len, s2, s2 + len - 1);
          node->right =
              //                                    4           6       3 5
              work(preorder, postorder, s1 + 1 + len, e1, s2 + len, e2 - 1);
          return node;
        }
        return nullptr;
      }
      return nullptr;
    }
  };
}