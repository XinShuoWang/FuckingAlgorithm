//
// Created by XinShuo Wang on 2021/12/25 13:09
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "ListNode.h"
#include "TreeNode.h"

TEST(leetcode_1609, 1) {
  using namespace std;
  class Solution {
   public:
    bool isEvenOddTree(TreeNode* root) {
      queue<TreeNode*> q;
      q.push(root);
      int level = 1;
      while (!q.empty()) {
        int size = q.size();
        int start = level % 2 == 0 ? INT_MAX : INT_MIN;
        auto compare = [&](int x, int y) -> bool {
          if (level % 2 == 0) {
            return x < y;
          } else {
            return x > y;
          }
        };
        while (size > 0) {
          auto head = q.front();
          //cout << start << "," << head->val << endl;
          if ((head->val % 2 != level % 2) || !compare(head->val, start)){
            return false;
          }else{
            start = head->val;
          }
          if (head->left != nullptr) q.push(head->left);
          if (head->right != nullptr) q.push(head->right);
          size--, q.pop();
        }
        level++;
      }
      return true;
    }
  };
}