//
// Created by xinsh on 2021/8/3.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include "Node.h"

TEST(tree_589, 1) {
    using namespace std;
    class Solution {
    public:
        vector<int> preorder(Node *root) {
            vector<int> v;
            work(root, v);
            return v;
        }

        void work(Node *root, vector<int> &v) {
            if (root == nullptr) return;
            v.push_back(root->val);
            for (Node *node:root->children) {
                work(node, v);
            }
        }
    };
}

TEST(tree_589, stack) {
    using namespace std;
    class Solution {
    public:
        vector<int> preorder(Node *root) {
            stack < Node * > s;
            vector<int> v;
            while (root != nullptr || !s.empty()) {
                while (root != nullptr) {
                    if (!root->children.empty()) {
                        for (Node *node:root->children) {
                            s.push(node);
                        }
                        root = root->children[0];
                    } else {
                        break;
                    }
                }
                root = s.top();
                s.pop();
            }
            return v;
        }
    };
}
