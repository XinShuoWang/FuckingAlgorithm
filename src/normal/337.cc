//
// Created by XinShuo Wang on 2021/12/22 15:08
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "ListNode.h"
#include "TreeNode.h"

TEST(leetcode_337, 1) {
  using namespace std;
  class Solution {
    unordered_map<pair<TreeNode*, bool>, int> cache;
    unordered_map<pair<TreeNode*, bool>, int>::iterator it;

   public:
    int dfs(TreeNode* root, bool chosen) {
      if (root == nullptr) return 0;
      if ((it = cache.find(make_pair(root, chosen))) != cache.end())
        return it->second;
      int ans;
      if (chosen) {
        int a = dfs(root->left, true) + dfs(root->right, true);
        int b = root->val + dfs(root->left, false) + dfs(root->right, false);
        ans = max(a, b);
      } else {
        ans = dfs(root->left, true) + dfs(root->right, true);
      }
      cache[make_pair(root, chosen)] = ans;
      return ans;
    }

    int rob(TreeNode* root) { return max(dfs(root, false), dfs(root, true)); }
  };
}