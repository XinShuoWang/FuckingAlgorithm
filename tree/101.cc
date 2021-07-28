//
// Created by xinsh on 2021/7/28.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(tree, BFS) {
    using namespace std;

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {}

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    class Solution {
    public:
        bool isSymmetric(TreeNode *root) {
            if (root->left == nullptr && root->right == nullptr) {
                return true;
            } else if (root->left == nullptr && root->right != nullptr) {
                return false;
            } else if (root->left != nullptr && root->right == nullptr) {
                return false;
            }
            return isOk(root->left, root->right);
        }

        bool isOk(TreeNode *p, TreeNode *q) {
            if (p == nullptr && q == nullptr) {
                return true;
            } else if (p != nullptr && q == nullptr) {
                return false;
            } else if (p == nullptr && q != nullptr) {
                return false;
            } else if (p->val != q->val) {
                return false;
            } else {
                return isOk(p->left, q->right) && isOk(p->right, q->left);
            }
        }
    };
}

TEST(tree, DFS) {
    using namespace std;

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {}

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    class Solution {
    public:
        bool isSymmetric(TreeNode *root) {
            if (root->left == nullptr && root->right == nullptr) {
                return true;
            } else if (root->left == nullptr && root->right != nullptr) {
                return false;
            } else if (root->left != nullptr && root->right == nullptr) {
                return false;
            }
            return isOk(root->left, root->right);
        }

        bool isOk(TreeNode *p, TreeNode *q) {
            queue < TreeNode * > q1, q2;
            if (p != nullptr) {
                q1.push(p);
            }
            if (q != nullptr) {
                q2.push(q);
            }
            if (q1.empty() && q2.empty()) {
                return true;
            }
            if (q1.size() != q2.size()) {
                return false;
            }
            // 到此为止，q1与q2应该是大小相等，且都不为空
            while (true) {
                if (q1.front()->val != q2.front()->val) {
                    return false;
                }
                if (q1.front()->left != nullptr && q2.front()->right != nullptr) {
                    q1.push(q1.front()->left);
                    q2.push(q2.front()->right);
                } else if (q1.front()->left == nullptr && q2.front()->right != nullptr) {
                    return false;
                } else if (q1.front()->left != nullptr && q2.front()->right == nullptr) {
                    return false;
                }
                if (q1.front()->right != nullptr && q2.front()->left != nullptr) {
                    q1.push(q1.front()->right);
                    q2.push(q2.front()->left);
                } else if (q1.front()->right == nullptr && q2.front()->left != nullptr) {
                    return false;
                } else if (q1.front()->right != nullptr && q2.front()->left == nullptr) {
                    return false;
                }
                q1.pop();
                q2.pop();
                if (q1.size() != q2.size()) {
                    return false;
                }
                if (q1.empty() && q2.empty()) {
                    return true;
                }
            }
        }
    };
}
