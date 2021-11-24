//
// Created by XinShuo Wang on 2021/11/23 10:28
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

TEST(leetcode_61, 1) {
  using namespace std;
  class Solution {
   public:
    ListNode* rotateRight(ListNode* head, int k) {
      int len = 0;
      ListNode* move = head;
      list<ListNode*> l;
      while (move != nullptr) {
        l.push_back(move);
        move = move->next;
        len++;
      }
      if (len == 0) return nullptr;
      k %= len;
      while (k > 0) {
        l.push_front(l.back());
        l.pop_back();
        k--;
      }
      ListNode* ans;
      ans = move = l.front();
      l.pop_front();
      while (!l.empty()) {
        move->next = l.front();
        l.pop_front();
        move = move->next;
      }
      move->next = nullptr;
      return ans;
    }
  };
}