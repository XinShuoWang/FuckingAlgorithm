//
// Created by xinsh on 2021/8/2.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include "TreeNode.h"

TEST(tree_513, BFS) {
    using namespace std;
    class Solution {
    public:
        int findBottomLeftValue(TreeNode *root) {
            queue < TreeNode * > q;
            vector <vector<int>> v;
            q.push(root);
            while (!q.empty()) {
                int size = q.size();
                vector<int> t;
                while (size > 0) {
                    t.push_back(q.front()->val);
                    if (q.front()->left != nullptr) q.push(q.front()->left);
                    if (q.front()->right != nullptr) q.push(q.front()->right);
                    size--;
                    q.pop();
                }
                v.push_back(t);
            }
            return v[v.size() - 1][0];
        }
    };
}

TEST(tree_513, DFS) {
    using namespace std;
    class Solution {
    private:
        int level_;
        int value_;
    public:
        Solution() {
            level_ = -1;
            value_ = 0;
        }

        int findBottomLeftValue(TreeNode *root) {
            dfs(root, 0);
            return value_;
        }

        void dfs(TreeNode *root, int level) {
            if (root == nullptr) return;
            if (level > level_) {
                level_ = level;
                value_ = root->val;
            }
            dfs(root->left, level + 1);
            dfs(root->right, level + 1);
        }
    };
}
