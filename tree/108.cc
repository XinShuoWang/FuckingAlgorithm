//
// Created by xinsh on 2021/8/3.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include "TreeNode.h"

TEST(tree_108, 1) {
    using namespace std;
    class Solution {
    public:
        TreeNode *sortedArrayToBST(vector<int> &nums) {
            return work(nums, 0, nums.size());
        }

        TreeNode *work(vector<int> &nums, int start, int end) {
            if (start < end) {
                int index = (end - start) / 2 + start;
                TreeNode *node = new TreeNode(nums[index]);
                node->left = work(nums, start, index);
                node->right = work(nums, index, end);
                return node;
            }
            return nullptr;
        }
    };
}


TEST(tree_108, 2) {
    using namespace std;
    class Solution {
    public:
        TreeNode *sortedArrayToBST(vector<int> &nums) {
            return work(nums, 0, nums.size() - 1);
        }

        TreeNode *work(vector<int> &nums, int start, int end) {
            if (start <= end) {
                int index = (end - start) / 2 + start;
                TreeNode *node = new TreeNode(nums[index]);
                node->left = work(nums, start, index - 1);
                node->right = work(nums, index + 1, end);
                return node;
            }
            return nullptr;
        }
    };
}
