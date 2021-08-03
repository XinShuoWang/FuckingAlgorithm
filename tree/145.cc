//
// Created by xinsh on 2021/8/3.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include "TreeNode.h"

TEST(tree_145, recursion) {
    using namespace std;
    class Solution {
    public:
        vector<int> postorderTraversal(TreeNode *root) {
            vector<int> v;
            work(v, root);
            return v;
        }

        void work(vector<int> &v, TreeNode *root) {
            if (root == nullptr) return;
            work(v, root->left);
            work(v, root->right);
            v.push_back(root->val);
        }
    };
}
