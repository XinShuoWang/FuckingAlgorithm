//
// Created by xinsh on 2021/8/4.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include "TreeNode.h"

TEST(tree_257, 1) {
    using namespace std;
    class Solution {
    private:
        set<vector<int>> set_;
        vector<int> path_;
    public:
        vector<string> binaryTreePaths(TreeNode *root) {
            vector <string> r;
            if (root == nullptr) return r;
            dfs(root, nullptr);
            for (const vector<int> &v: set_) {
                string tt;
                int i;
                for (i = 0; i < v.size() - 1; ++i) {
                    // 这里的to_string方法很有用
                    tt.append(to_string(v[i]));
                    tt.append("->");
                }
                // 最后一个不需要“->”
                tt.append(to_string(v[i]));
                r.push_back(tt);
            }
            return r;
        }

        void dfs(TreeNode *root, TreeNode *father) {
            if (root == nullptr) {
                // 这里需要进行判断是因为有的节点不是叶子节点也向结果集添加了路径
                if (father->left == nullptr && father->right == nullptr) {
                    // 使用set的原因是因为叶子结点的左右节点都会导致进入这段逻辑，所以使用set去重
                    set_.insert(path_);
                }
                return;
            }
            path_.push_back(root->val);
            dfs(root->left, root);
            dfs(root->right, root);
            // 类似于回溯
            path_.pop_back();
        }
    };
}
