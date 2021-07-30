//
// Created by xinsh on 2021/7/29.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include "TreeNode.h"

TEST(tree_111, BFS) {
    using namespace std;

    class Solution {
    public:
        int minDepth(TreeNode *root) {
            queue < TreeNode * > q;
            int level = 0;
            if (root == nullptr) return 0;
            q.push(root);
            while (!q.empty()) {
                int size = q.size();
                while (size > 0) {
                    if (q.front()->right == nullptr && q.front()->left == nullptr) {
                        return level;
                    }
                    if (q.front()->right != nullptr) {
                        q.push(q.front()->right);
                    }
                    if (q.front()->left != nullptr) {
                        q.push(q.front()->left);
                    }
                    q.pop();
                    size--;
                }
                level++;
            }
            return level;
        }
    };
}

TEST(tree_111, DFS) {
    using namespace std;

    class Solution {
    public:
        int minDepth(TreeNode *root) {
            if (root == nullptr)return 0;
            int left = minDepth(root->left);
            int right = minDepth(root->right);
            if (left == 0 && right == 0) {
                return 1;
            }
            if (left != 0 && right == 0) {
                return left + 1;
            }
            if (left == 0 && right != 0) {
                return right + 1;
            }
            if (left != 0 && right != 0) {
                return min(left, right) + 1;
            }
            return 0;
        }
    };
}