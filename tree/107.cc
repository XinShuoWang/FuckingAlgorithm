//
// Created by xinsh on 2021/7/31.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include "TreeNode.h"

TEST(tree_107, 107) {
    using namespace std;
    class Solution {
    public:
        vector<vector<int>> levelOrderBottom(TreeNode *root) {
            vector <vector<int>> res;
            if (root == nullptr) return res;
            queue < TreeNode * > q;
            q.push(root);
            while (!q.empty()) {
                int size = q.size();
                vector<int> v;
                while (size > 0) {
                    TreeNode *t = q.front();
                    v.push_back(t->val);
                    if (t->left != nullptr) q.push(t->left);
                    if (t->right != nullptr) q.push(t->right);
                    q.pop();
                    size--;
                }
                res.push_back(v);
            }
            reverse(res.begin(), res.end());
            return res;
        }
    };
}
