//
// Created by XinShuo Wang on 2021/11/26 12:19
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

TEST(leetcode_263, 1) {
  using namespace std;
  class Solution {
   public:
    bool dfs(long long n, long long v) {
      if (v > n) return false;
      if (v == n) return true;
      int ans = false;
      for (int vv : {2, 3, 5}) {
        ans |= dfs(n, v * vv);
        if (ans) return true;
      }
      return ans;
    }

    bool isUgly(int n) {
      if (n == 1) return true;
      if (n <= 0) return false;
      return dfs(n, 1);
    }
  };
}

TEST(leetcode_263, 2) {
  using namespace std;
  class Solution {
   public:
    bool isUgly(int n) {
      if (n <= 0) return false;
      if (n == 1 || n == 2 || n == 3 || n == 5) return true;
      bool ans = false;
      if (n % 2 == 0) {
        ans |= isUgly(n / 2);
        if (ans) return ans;
      }
      if (n % 3 == 0) {
        ans |= isUgly(n / 3);
        if (ans) return ans;
      }
      if (n % 5 == 0) {
        ans |= isUgly(n / 5);
        if (ans) return ans;
      }
      return ans;
    }
  };
}