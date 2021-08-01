//
// Created by xinsh on 2021/7/31.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include "TreeNode.h"

TEST(tree_114, DFS) {
    using namespace std;
    class Solution {
    public:
        void flatten(TreeNode *root) {
            vector < TreeNode * > v;
            dfs(root, v);
            for (int i = 0; i < v.size() - 1; ++i) {
                v[i]->left = nullptr;
                v[i]->right = v[i + 1];
            }
            int i = v.size() - 1;
            v[i]->left = nullptr;
            v[i]->right = nullptr;
        }

        void dfs(TreeNode *root, vector<TreeNode *> &res) {
            if (root == nullptr) return;
            res.push_back(root);
            dfs(root->left, res);
            dfs(root->right, res);
        }
    };
}

TEST(tree_114, 114_2) {
    using namespace std;
    class Solution {
    public:
        void flatten(TreeNode *root) {
            if (root == nullptr) return;
            stack < TreeNode * > s;
            vector < TreeNode * > v;
            while (root != nullptr || !s.empty()) {
                while (root != nullptr) {
                    v.push_back(root);
                    s.push(root);
                    root = root->left;
                }
                root = s.top()->right;
                s.pop();
            }
            for (int i = 0; i < v.size() - 1; ++i) {
                v[i]->left = nullptr;
                v[i]->right = v[i + 1];
            }
        }
    };

    TreeNode a1(1), a2(2), a3(3), a4(4), a5(5), a6(6);
    a1.left = &a2;
    a1.right = &a5;
    a2.left = &a3;
    a2.right = &a4;
    a5.right = &a6;
    Solution solution;
    solution.flatten(&a1);
}