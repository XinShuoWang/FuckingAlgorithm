//
// Created by XinShuo Wang on 2021/10/22 9:21
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "TreeNode.h"

TEST(leetcode_jz_34, 1) {
  using namespace std;
  class Solution {
    vector<int> path;
    vector<vector<int>> ans;

   public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
      if (root == nullptr) {
        return vector<vector<int>>{{}};
      }
      path.push_back(root->val);
      work(root, target - root->val);
      return ans;
    }

    void work(TreeNode* root, int target) {
      if (root->left == nullptr && root->right == nullptr) {
        if (target == 0) ans.push_back(path);
        return;
      }
      if (root->left != nullptr) {
        path.push_back(root->left->val);
        work(root->left, target - root->left->val);
        path.pop_back();
      }
      if (root->right != nullptr) {
        path.push_back(root->right->val);
        work(root->left, target - root->right->val);
        path.pop_back();
      }
    }
  };
}