//
// Created by XinShuoWang on 2021/8/6.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "TreeNode.h"

TEST(tree_103, 1) {
  using namespace std;
  class Solution {
   public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      if (root == nullptr) return vector<vector<int>>{};
      vector<vector<int>> res;
      int h = 1;
      queue<TreeNode*> q;
      q.push(root);
      while (!q.empty()) {
        int size = q.size();
        vector<int> t;
        while (size > 0) {
          t.push_back(q.front()->val);
          if (q.front()->left != nullptr) q.push(q.front()->left);
          if (q.front()->right != nullptr) q.push(q.front()->right);
          q.pop();
          size--;
        }
        if (h % 2 == 0) reverse(t.begin(), t.end());
        h++;
        res.push_back(t);
      }
      return res;
    }
  };
}