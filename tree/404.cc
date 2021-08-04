//
// Created by xinsh on 2021/8/4.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include "TreeNode.h"

TEST(tree_404, 1) {
    using namespace std;
    class Solution {
    public:
        int sumOfLeftLeaves(TreeNode *root) {
            if (root == nullptr) return 0;
            return work(root->left, true) + work(root->right, false);
        }

        int work(TreeNode *root, bool isLeft) {
            if (root == nullptr) return 0;
            if (root->left == nullptr && root->right == nullptr && isLeft) return root->val;
            return work(root->left, true) + work(root->right, false);
        }
    };
}
