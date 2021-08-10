//
// Created by XinShuoWang on 2021/8/9.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "TreeNode.h"

TEST(tree_654, 1) {
  using namespace std;
  class Solution {
   public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
      return work(nums, 0, nums.size() - 1);
    }

    TreeNode* work(vector<int>& nums, int start, int end) {
      if (start == end) return new TreeNode(nums[start]);
      if (start < end) {
        int index = start, v = nums[start];
        for (int i = start; i <= end; ++i) {
          if (nums[i] > v) {
            index = i;
            v = nums[i];
          }
        }
        auto node = new TreeNode(nums[index]);
        node->left = work(nums, start, index - 1);
        node->right = work(nums, index + 1, end);
        return node;
      }
      return nullptr;
    }
  };
}