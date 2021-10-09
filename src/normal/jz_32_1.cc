//
// Created by XinShuo Wang on 2021/10/9 9:03
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "TreeNode.h"

TEST(leetcode_jz_32, 1) {
  using namespace std;
  class Solution {
   public:
    vector<int> levelOrder(TreeNode* root) {
      if (root == nullptr) return vector<int>{};
      vector<int> ans;
      queue<TreeNode*> q;
      q.push(root);
      while (!q.empty()) {
        ans.push_back(q.front()->val);
        if (q.front()->left != nullptr) q.push(q.front()->left);
        if (q.front()->right != nullptr) q.push(q.front()->right);
        q.pop();
      }
      return ans;
    }
  };
}