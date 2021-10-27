//
// Created by XinShuo Wang on 2021/10/23 10:25
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

TEST(leetcode_jz_07, 1) {
  using namespace std;
  class Solution {
   public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      if(preorder.size()==0) return nullptr;
      return work(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }

    TreeNode* work(vector<int>& preorder, int a, int b, vector<int>& inorder,
                   int c, int d) {
      TreeNode* root = new TreeNode(preorder[a]);
      if (a == b) return root;
      int idx = c;
      while (inorder[idx] != preorder[a]) idx++;
      int left_len = idx - c;
      root->left = work(preorder, a + 1, a + left_len, inorder, c, idx - 1);
      root->right = work(preorder, a + left_len + 1, b, inorder, idx + 1, d);
      return root;
    }
  };
}