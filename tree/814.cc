//
// Created by xinsh on 2021/8/3.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include "TreeNode.h"

TEST(tree_814, 1) {
    using namespace std;
    class Solution {
    public:
        // 思路：先来到树的最底面（后序遍历），检查是不是可以删除这个叶子结点
        // 如果可以的话就返回null
        TreeNode *pruneTree(TreeNode *root) {
            if (root == nullptr) return nullptr;
            root->left = pruneTree(root->left);
            root->right = pruneTree(root->right);
            return (root->val == 0 && root->left == nullptr && root->right == nullptr) ? nullptr : root;
        }
    };
}
