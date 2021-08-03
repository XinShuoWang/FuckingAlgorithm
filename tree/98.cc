//
// Created by xinsh on 2021/8/2.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include "TreeNode.h"

TEST(tree_98, 98) {
    using namespace std;
    class Solution {
    public:
        typedef long long ll;

        bool isValidBST(TreeNode *root) {
            if (root == nullptr) return true;
            // 为什么是long long呢？
            vector <ll> v;
            work(root, v);
            for (int i = 0; i < v.size() - 1; ++i) {
                // 这一步的减法有可能越界
                if (v[i] - v[i + 1] >= 0) return false;
            }
            return true;
        }

        void work(TreeNode *root, vector<ll> &v) {
            if (root == nullptr) return;
            work(root->left, v);
            v.push_back(root->val);
            work(root->right, v);
        }
    };
}

TEST(tree_98, 2) {
    using namespace std;
    class Solution {
    public:
        typedef long long ll;

        bool isValidBST(TreeNode *root) {
            return work(root, LONG_MIN, LONG_MAX);
        }

        bool work(TreeNode *root, ll left, ll right) {
            if (root == nullptr) return true;
            if (root->val <= left || root->val >= right) return false;
            return work(root->left, left, root->val) && work(root->right, root->val, right);
        }
    };
}