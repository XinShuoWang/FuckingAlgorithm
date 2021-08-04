//
// Created by xinsh on 2021/8/4.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include "TreeNode.h"

TEST(tree_501, 1) {
    using namespace std;
    class Solution {
    private:
        vector<int> v;
        map<int, int> m;
    public:
        vector<int> findMode(TreeNode *root) {
            dfs(root);
            vector<int> res;
            if (v.size() == 0) return res;
            int max = -1;
            for (int i = 0; i < v.size(); ++i) {
                if (m.count(v[i]) == 0) m[v[i]] = 1;
                else m[v[i]] += 1;
                max = max < m[v[i]] ? m[v[i]] : max;
            }
            for (const pair<const int, int> &kv: m) {
                if (kv.second == max) res.push_back(kv.first);
            }
            return res;
        }

        void dfs(TreeNode *root) {
            if (root == nullptr) return;
            dfs(root->left);
            v.push_back(root->val);
            dfs(root->right);
        }
    };
}
