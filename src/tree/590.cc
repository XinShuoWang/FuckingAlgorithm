//
// Created by xinsh on 2021/8/3.
//

#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "Node.h"

TEST(tree_590, 1) {
  using namespace std;
  class Solution {
   public:
    vector<int> postorder(Node* root) {
      vector<int> v;
      work(root, v);
      return v;
    }

    void work(Node* root, vector<int>& v) {
      if (root == nullptr) return;
      for (Node* node : root->children) {
        work(node, v);
      }
      v.push_back(root->val);
    }
  };
}