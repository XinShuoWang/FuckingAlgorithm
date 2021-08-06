//
// Created by xinsh on 2021/7/31.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "TreeNode.h"

TEST(tree_222, BFS) {
  using namespace std;
  class Solution {
   public:
    int countNodes(TreeNode* root) {
      if (root == nullptr) return 0;
      vector<int> v;
      queue<TreeNode*> q;
      q.push(root);
      while (!q.empty()) {
        v.push_back(q.front()->val);
        cout << q.front()->val << endl;
        if (q.front()->left != nullptr) q.push(q.front()->left);
        if (q.front()->right != nullptr) q.push(q.front()->right);
        q.pop();
      }
      return v.size();
    }
  };
}

TEST(tree_222, DFS) {
  using namespace std;
  class Solution {
   public:
    int countNodes(TreeNode* root) {
      if (root == nullptr) return 0;
      return countNodes(root->left) + countNodes(root->right) + 1;
    }
  };
}

TEST(tree_222, binary_search) {
  using namespace std;
  class Solution {
   public:
    int countNodes(TreeNode* root) {
      if (root == nullptr) return 0;
      int level = -1;
      TreeNode* temp = root;
      while (temp != nullptr) {
        level++;
        temp = temp->left;
      }
      for (int i = (1 << (level + 1)) - 1; i >= (1 << level); --i) {
        if (exist(root, i, level)) return i;
      }
      return 0;
    }

    bool exist(TreeNode* root, int val, int bits) {
      val -= (1 << bits);
      bits -= 1;
      TreeNode* temp = root;
      while (bits >= 0) {
        if ((val & (1 << bits)) != 0) {
          if (temp == nullptr) return false;
          temp = temp->right;
        } else {
          if (temp == nullptr) return false;
          temp = temp->left;
        }
        bits--;
      }
      return temp != nullptr;
    }
  };
}