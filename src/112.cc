//
// Created by xinsh on 2021/7/29.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "TreeNode.h"

TEST(tree_112, QAQ) {
  using namespace std;
  class Solution {
   public:
    bool hasPathSum(TreeNode* root, int targetSum) {
      if (root == nullptr) return false;
      vector<int> res;
      aaa(root, res, 0);
      for (int a : res) {
        if (a == targetSum) return true;
      }
      return false;
    }

    void aaa(TreeNode* root, vector<int> bb, int ss) {
      if (root->left == nullptr && root->right == nullptr) {
        bb.push_back(ss + root->val);
      } else {
        if (root->left != nullptr) {
          aaa(root->left, bb, ss + root->val);
        }
        if (root->right != nullptr) {
          aaa(root->right, bb, ss + root->val);
        }
      }
    }
  };
}

TEST(tree_112, DFS) {
  using namespace std;
  class Solution {
   public:
    bool hasPathSum(TreeNode* root, int targetSum) {
      if (root == nullptr) return false;
      if (root->left == nullptr && root->right == nullptr)
        return targetSum == root->val;
      return hasPathSum(root->left, targetSum - root->val) ||
             hasPathSum(root->right, targetSum - root->val);
    }
  };
}

TEST(tree_112, BFS) {
  using namespace std;
  class Solution {
   public:
    bool hasPathSum(TreeNode* root, int targetSum) {
      if (root == nullptr) return false;
      queue<TreeNode*> q1;
      queue<int> q2;
      q1.push(root);
      q2.push(root->val);
      while (!q1.empty()) {
        if (q1.front()->left != nullptr) {
          q2.push(q2.front() + q1.front()->left->val);
          q1.push(q1.front()->left);
        }
        if (q1.front()->right != nullptr) {
          q2.push(q2.front() + q1.front()->right->val);
          q1.push(q1.front()->right);
        }
        if (q1.front()->left == nullptr && q1.front()->right == nullptr &&
            targetSum == q2.front()) {
          return true;
        }
        q1.pop();
        q2.pop();
      }
      return false;
    }
  };
}