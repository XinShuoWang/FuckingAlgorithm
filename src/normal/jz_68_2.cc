//
// Created by XinShuo Wang on 2021/10/24 19:22
//

/**
 *                             _ooOoo_
 *                            o8888888o
 *                            88" . "88
 *                            (| -_- |)
 *                            O\  =  /O
 *                         ____/`---'\____
 *                       .'  \\|     |//  `.
 *                      /  \\|||  :  |||//  \
 *                     /  _||||| -:- |||||-  \
 *                     |   | \\\  -  /// |   |
 *                     | \_|  ''\---/''  |   |
 *                     \  .-\__  `-`  ___/-. /
 *                   ___`. .'  /--.--\  `. . __
 *                ."" '<  `.___\_<|>_/___.'  >'"".
 *               | | :  `- \`.;`\ _ /`;.`/ - ` : | |
 *               \  \ `-.   \_ __\ /__ _/   .-` /  /
 *          ======`-.____`-.___\_____/___.-`____.-'======
 *                             `=---='
 *          ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
 *                     佛祖保佑        永无BUG
 *            佛曰:
 *                   写字楼里写字间，写字间里程序员；
 *                   程序人员写程序，又拿程序换酒钱。
 *                   酒醒只在网上坐，酒醉还来网下眠；
 *                   酒醉酒醒日复日，网上网下年复年。
 *                   但愿老死电脑间，不愿鞠躬老板前；
 *                   奔驰宝马贵者趣，公交自行程序员。
 *                   别人笑我忒疯癫，我笑自己命太贱；
 *                   不见满街漂亮妹，哪个归得程序员？
 */

#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "ListNode.h"
#include "TreeNode.h"

TEST(leetcode_jz_68_2, 1) {
  using namespace std;
  class Solution {
   public:
    bool in(TreeNode* root, int val) {
      if (root == nullptr) return false;
      if (root->val == val) return true;
      return in(root->left, val) || in(root->right, val);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      if (root == nullptr) return nullptr;
      bool p_in_left = in(root->left, p->val);
      bool q_in_left = in(root->left, q->val);
      if(root->val == p->val || root->val == q->val){
        return root;
      }
      if (p_in_left && q_in_left) {
        return lowestCommonAncestor(root->left, p, q);
      } else if (p_in_left && !q_in_left) {
        return root;
      } else if (!p_in_left && q_in_left) {
        return root;
      } else {
        return lowestCommonAncestor(root->right, p, q);
      }
    }
  };
}