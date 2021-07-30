//
// Created by xinsh on 2021/7/29.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include "TreeNode.h"


TEST(tree_144, recursion) {
    using namespace std;
    class Solution {
    public:
        vector<int> preorderTraversal(TreeNode *root) {
            if (root == nullptr) {
                vector<int> v;
                return v;
            }
            vector<int> v;
            v.push_back(root->val);
            vector<int> v1 = preorderTraversal(root->left);
            vector<int> v2 = preorderTraversal(root->right);
            v.insert(v.end(), v1.begin(), v1.end());
            v.insert(v.end(), v2.begin(), v2.end());
            return v;
        }
    };
}

TEST(tree_144, iteration) {
    using namespace std;
    class Solution {
    public:
        vector<int> preorderTraversal(TreeNode *root) {
            vector<int> v;
            stack < TreeNode * > s;
            TreeNode *p = root;
            while (p != nullptr || !s.empty()) {
                while (p != nullptr) {
                    v.push_back(p->val);
                    s.push(p);
                    p = p->left;
                }
                p = s.top();
                s.pop();
                p = p->right;
            }
            return v;
        }
    };
}