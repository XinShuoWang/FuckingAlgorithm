//
// Created by XinShuo Wang on 2021/10/9 9:06
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "TreeNode.h"

TEST(leetcode_jz_32_2, 1) {
  using namespace std;
  class Solution {
   public:
    vector<vector<int>> levelOrder(TreeNode* root) {
      vector<vector<int>> ans;
      if (root == nullptr) return ans;
      queue<TreeNode*> q;
      q.push(root);
      while (!q.empty()) {
        int c = q.size();
        vector<int> t;
        while (c > 0) {
          t.push_back(q.front()->val);
          if (q.front()->left != nullptr) q.push(q.front()->left);
          if (q.front()->right != nullptr) q.push(q.front()->right);
          q.pop();
          c--;
        }
        ans.emplace_back(t);
      }
      return ans;
    }
  };
}