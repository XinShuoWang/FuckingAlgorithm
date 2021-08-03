//
// Created by xinsh on 2021/8/3.
//

#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include "Node.h"

TEST(tree_559, 1) {
    using namespace std;
    class Solution {
    public:
        int maxDepth(Node *root) {
            if (root == nullptr) return 0;
            int val = 1;
            for (Node *node: root->children) {
                int level = maxDepth(node) + 1;
                if (val < level) val = level;
            }
            return val;
        }
    };
}
