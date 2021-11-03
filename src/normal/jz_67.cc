//
// Created by XinShuo Wang on 2021/11/3 10:12
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

TEST(leetcode_jz_67, 1) {
  using namespace std;
  class Solution {
   public:
    int strToInt(string str) {
      int i = 0;
      while (str[i] == ' ') ++i;
      if (str[i] == '-') {
        ++i;
        if (i >= str.length()) return 0;
        long long ans = 0;
        while (str[i] <= '9' && str[i] >= '0' && i < str.length()) {
          ans *= 10;
          ans += str[i] - '0';
          ++i;
          if (-1 * ans < INT_MIN) return INT_MIN;
        }
        return -1 * ans < INT_MIN ? INT_MIN : -1 * ans;
      } else if (str[i] <= '9' && str[i] >= '0') {
        long long ans = 0;
        while (str[i] <= '9' && str[i] >= '0' && i < str.length()) {
          ans *= 10;
          ans += str[i] - '0';
          ++i;
          if (ans > INT_MAX) return INT_MAX;
        }
        return ans > INT_MAX ? INT_MAX : ans;
      } else if (str[i] == '+') {
        ++i;
        if (i >= str.length()) return 0;
        long long ans = 0;
        while (str[i] <= '9' && str[i] >= '0' && i < str.length()) {
          ans *= 10;
          ans += str[i] - '0';
          ++i;
          if (ans > INT_MAX) return INT_MAX;
        }
        return ans > INT_MAX ? INT_MAX : ans;
      }
      return 0;
    }
  };
}