//
// Created by XinShuo Wang on 2021/11/26 12:20
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

TEST(leetcode_264, 1) {
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

    int nthUglyNumber(int n) {
      int ans, count = 1;
      for (int i = 0; i < n; ++i) {
        while (!isUgly(count)) count++;
        ans = count++;
      }
      return ans;
    }
  };
}

TEST(leetcode_264, 2) {
  using namespace std;
  class Solution {
   public:
    typedef long long ll;

    int nthUglyNumber(ll n) {
      array<int, 3> factors{2, 3, 5};
      priority_queue<ll, vector<ll>, greater<ll>> q;
      unordered_set<ll> seen;
      q.push(1);
      seen.insert(1);
      ll ans;
      for (int i = 0; i < n; ++i) {
        ll curr = q.top();
        q.pop();
        ans = curr;
        for (auto factor : factors) {
          if(seen.find(factor*curr)==seen.end()){
            seen.insert(factor*curr);
            q.push(factor*curr);
          }
        }
      }
      return ans;
    }
  };
}