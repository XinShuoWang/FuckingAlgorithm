//
// Created by xinsh on 2021/8/2.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include "TreeNode.h"

TEST(tree_113, BFS) {
    using namespace std;
    class Solution {
    public:
        vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
            vector <vector<int>> res;
            if (root == nullptr) return res;
            queue < TreeNode * > q1;
            queue <vector<int>> q2, q3;
            q1.push(root);
            q2.push(vector < int > {root->val});
            while (!q1.empty()) {
                TreeNode *t1 = q1.front();
                if (t1->left != nullptr) {
                    vector<int> t2{q2.front()};
                    t2.push_back(t1->left->val);
                    q2.push(t2);
                    q1.push(t1->left);
                }
                if (t1->right != nullptr) {
                    vector<int> t2{q2.front()};
                    t2.push_back(t1->right->val);
                    q2.push(t2);
                    q1.push(t1->right);
                }
                if (t1->left == nullptr && t1->right == nullptr) {
                    q3.push(vector < int > {q2.front()});
                }
                q1.pop();
                q2.pop();
            }
            while (!q3.empty()) {
                vector<int> v{q3.front()};
                int sum = 0;
                for (int value:v) {
                    sum += value;
                }
                if (sum == targetSum) res.push_back(v);
                q3.pop();
            }
            return res;
        }
    };
}


TEST(tree_113, DFS) {
    using namespace std;
    class Solution {
    private:
        vector<vector<int>> res_;
        vector<int> path_;
    public:
        vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
            helper(root, targetSum);
            return res_;
        }

        // 感觉有点类似回溯法
        void helper(TreeNode *root, int targetSum) {
            if (root == nullptr) return;
            path_.push_back(root->val);
            targetSum -= root->val;
            if (targetSum == 0 && root->left == nullptr && root->right == nullptr) {
                res_.push_back(path_);
            }
            helper(root->left, targetSum);
            helper(root->right, targetSum);
            // 这一步是回溯算法的精髓
            // 回溯算法一般会有全局变量需要修改，所以要撤回才不会影响其他状态的搜索
            path_.pop_back();
        }
    };

    Solution solution;
    TreeNode a1(1), a2(2), a3(3);
    a1.left = &a2;
    a1.right = &a3;
    solution.pathSum(&a1, 3);
}