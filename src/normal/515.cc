//
// Created by XinShuoWang on 2021/8/9.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "TreeNode.h"

TEST(tree_515, BFS) {
  using namespace std;
  class Solution {
   public:
    vector<int> largestValues(TreeNode* root) {
      queue<TreeNode*> q;
      vector<int> res;
      if (root == nullptr) return res;
      q.push(root);
      while (!q.empty()) {
        int size = q.size();
        int m = INT_MIN;
        while (size > 0) {
          m = m < q.front()->val ? q.front()->val : m;
          if (q.front()->left != nullptr) q.push(q.front()->left);
          if (q.front()->right != nullptr) q.push(q.front()->right);
          q.pop();
          size--;
        }
        res.push_back(m);
      }
      return res;
    }
  };
}