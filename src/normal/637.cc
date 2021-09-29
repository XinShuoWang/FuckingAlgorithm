//
// Created by XinShuo Wang on 2021/9/27 10:07
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "TreeNode.h"

TEST(leetcode_637, 1) {
  using namespace std;
  class Solution {
   public:
    vector<double> averageOfLevels(TreeNode* root) {
      if (root == nullptr) return vector<double>{0};
      vector<double> ans;
      queue<TreeNode*> q;
      q.push(root);
      while (!q.empty()) {
        int size = q.size(), count = q.size();
        double val = 0;
        while (count > 0) {
          val += q.front()->val;
          if (q.front()->left != nullptr) q.push(q.front()->left);
          if (q.front()->right != nullptr) q.push(q.front()->right);
          q.pop();
          count--;
        }
        ans.push_back(val / size);
      }
      return ans;
    }
  };
}