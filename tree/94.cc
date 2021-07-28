//
// Created by xinsh on 2021/7/28.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>


TEST(tree, 94) {
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
        vector<int> inorderTraversal(TreeNode *root) {
            if (root == nullptr) {
                vector<int> v;
                return v;
            } else {
                vector<int> v1 = inorderTraversal(root->left);
                v1.push_back(root->val);
                vector<int> v2 = inorderTraversal(root->right);
                v1.insert(v1.end(), v2.begin(), v2.end());
                return v1;
            }
        }
    };
}

TEST(tree, 94_2) {
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
        vector<int> inorderTraversal(TreeNode *root) {
            vector<int> res;
            stack < TreeNode * > s;
            TreeNode *t = root;
            // 经过调试可以发现t != nullptr语句是为了保证第一次的时候可以正确运行而出现的，否则一开始就无法进入循环
            // 如果右树为空那么会直接从栈里面拿数据进行遍历，如果右子树不为空则进行压栈并遍历。
            while (t != nullptr || !s.empty()) {
                while (t != nullptr) {
                    s.push(t);
                    t = t->left;
                }
                t = s.top();
                s.pop();
                res.push_back(t->val);
                t = t->right;
            }
            return res;
        }
    };

    TreeNode* root=new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    Solution solution;
    vector<int> vv = solution.inorderTraversal(root);
}

