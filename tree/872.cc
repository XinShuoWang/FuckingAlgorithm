//
// Created by xinsh on 2021/8/3.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include "TreeNode.h"

TEST(tree_872, 1) {
    using namespace std;
    class Solution {
    public:
        bool leafSimilar(TreeNode *root1, TreeNode *root2) {
            vector<int> v1, v2;
            dfs(root1, v1);
            dfs(root2, v2);
            if (v1.size() != v2.size()) return false;
            for (int i = 0; i < v1.size(); ++i) {
                if (v1[i] != v2[i]) return false;
            }
            return true;
        }

        void dfs(TreeNode *root, vector<int> &v) {
            if (root == nullptr)return;
            if (root->left == nullptr && root->right == nullptr) v.push_back(root->val);
            dfs(root->left, v);
            dfs(root->right, v);
        }
    };
}
