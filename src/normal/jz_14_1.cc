//
// Created by XinShuo Wang on 2021/10/27 10:27
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

TEST(leetcode_jz_14_1, 1) {
  using namespace std;
  class Solution {
    map<pair<int, int>, int> m;
    map<pair<int, int>, int>::iterator it;

   public:
    int cuttingRope(int n) {
      switch (n) {
        case 1:
          return 1;
        case 2:
          return 1;
        case 3:
          return 2;
        case 4:
          return 4;
        default:
          return work(n, 1);
      }
    }

    int work(int n, int v) {
      if (n == 0) return v;
      if ((it = m.find(make_pair(n, v))) != m.end()) return it->second;
      int ans = INT_MIN;
      for (int i = 1; i <= n; ++i) {
        ans = max(ans, work(n - i, v * i));
      }
      m[make_pair(n, v)] = ans;
      return ans;
    }
  };
}