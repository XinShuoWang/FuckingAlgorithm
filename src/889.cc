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
      if (s1 <= e1 && s2 <= e2) {
      }
      return nullptr;
    }
  };
}