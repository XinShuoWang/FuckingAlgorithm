//
// Created by xinsh on 2021/7/29.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include "TreeNode.h"

TEST(tree, 111) {
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
                    if(q.front()->right != nullptr){
                        q.push(q.front()->right);
                    }
                    if(q.front()->left != nullptr){
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