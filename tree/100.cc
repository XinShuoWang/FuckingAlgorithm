//
// Created by xinsh on 2021/7/28.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include "TreeNode.h"

TEST(tree, dfs) {
    using namespace std;

    class Solution {
    public:
        bool isSameTree(TreeNode *p, TreeNode *q) {
            if (p == nullptr && q != nullptr) {
                return false;
            } else if (p != nullptr && q == nullptr) {
                return false;
            } else if (p == nullptr && q == nullptr) {
                return true;
            } else if (p->val == q->val) {
                // 不能贸然返回true，因为还没判断子树的相同与否
                return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
            } else {
                // 到这里只剩下p->val != q->val的情况
                return false;
            }
        }
    };
}

TEST(tree, bfs) {
    using namespace std;

    class Solution {
    public:
        bool isSameTree(TreeNode *p, TreeNode *q) {
            queue < TreeNode * > q1, q2;
            if (p != nullptr) {
                q1.push(p);
            }
            if (q != nullptr) {
                q2.push(q);
            }

            // 大小相同且为0的情况下符合要求
            if(q1.empty() && q2.empty()){
                return true;
            }
            if(q1.size() != q2.size()){
                return false;
            }

            while (true) {
                if (q1.front()->val != q2.front()->val) {
                    return false;
                }
                if (q1.front()->left != nullptr && q2.front()->left != nullptr) {
                    q1.push(q1.front()->left);
                    q2.push(q2.front()->left);
                } else if (q1.front()->left != nullptr && q2.front()->left == nullptr) {
                    return false;
                } else if (q1.front()->left == nullptr && q2.front()->left != nullptr) {
                    return false;
                } else {
                    // 所有的都为NULL
                }

                if (q1.front()->right != nullptr && q2.front()->right != nullptr) {
                    q1.push(q1.front()->right);
                    q2.push(q2.front()->right);
                } else if (q1.front()->right != nullptr && q2.front()->right == nullptr) {
                    return false;
                } else if (q1.front()->right == nullptr && q2.front()->right != nullptr) {
                    return false;
                } else {
                    // 所有的都为NULL
                }

                q1.pop();
                q2.pop();
                if(q1.size() != q2.size()){
                    return false;
                }
                if(q1.empty() && q2.empty()){
                    return true;
                }
            }
        }
    };
}
