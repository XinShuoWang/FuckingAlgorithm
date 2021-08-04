//
// Created by xinsh on 2021/8/4.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include "TreeNode.h"

TEST(tree_543, 1) {
    using namespace std;
    class Solution {
        int level;
    public:
        int diameterOfBinaryTree(TreeNode *root) {
            if (root == nullptr) return 0;
            int dis = depth(root->left) + depth(root->right);
            if (level < dis) level = dis;
            diameterOfBinaryTree(root->left);
            diameterOfBinaryTree(root->right);
            return level;
        }

        int depth(TreeNode *root) {
            if (root == nullptr) return 0;
            return 1 + max(depth(root->left), depth(root->right));
        }
    };
}
