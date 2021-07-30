//
// Created by xinsh on 2021/7/28.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include "TreeNode.h"

TEST(tree_104, 1) {
    using namespace std;

    class Solution {
    public:
        int maxDepth(TreeNode *root) {
            if (root == nullptr) return 0;
            return max(maxDepth(root->left), maxDepth(root->right)) + 1;
        }
    };
}

TEST(tree_104, 2) {
    using namespace std;

    class Solution {
        vector<int> res;
    public:
        int maxDepth(TreeNode *root) {
            my(root, 0);
            int aa = 0;
            for (int a:res) {
                if (aa < a) {
                    aa = a;
                }
            }
            return aa;
        }

        void my(TreeNode *root, int level) {
            if (root == nullptr) {
                res.push_back(level);
            } else {
                my(root->left, level + 1);
                my(root->right, level + 1);
            }
        }
    };
}


TEST(tree_104, 3) {
    using namespace std;

    class Solution {
    public:
        int maxDepth(TreeNode *root) {
            queue < TreeNode * > q;
            if (root == nullptr) return 0;
            q.push(root);
            int res = 1;
            while (!q.empty()) {
                int size = q.size();
                while (size > 0){
                    if (q.front()->left != nullptr) {
                        q.push(q.front()->left);
                    }
                    if (q.front()->right != nullptr) {
                        q.push(q.front()->right);
                    }
                    q.pop();
                    size--;
                }
                res++;
            }
            return res;
        }
    };
}