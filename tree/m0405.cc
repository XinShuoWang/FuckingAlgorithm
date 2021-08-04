//
// Created by xinsh on 2021/8/4.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include "TreeNode.h"

TEST(tree_m0405, 1) {
    using namespace std;
    class Solution {
        typedef long long ll;
    public:
        bool isValidBST(TreeNode *root) {
            return verify(root, LONG_MIN, LONG_MAX);
        }

        bool verify(TreeNode *root, ll left, ll right) {
            if (root == nullptr) return true;
            if (root->val <= left || root->val >= right) return false;
            if (root->val < right && root->val > left)
                return verify(root->left, left, root->val) && verify(root->right, root->val, right);
            return true;
        }
    };
}
