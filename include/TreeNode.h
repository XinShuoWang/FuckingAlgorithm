//
// Created by xinsh on 2021/7/29.
//

#ifndef FUCKINGALGORITHM_TREENODE_H
#define FUCKINGALGORITHM_TREENODE_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#endif //FUCKINGALGORITHM_TREENODE_H
