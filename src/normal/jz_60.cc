//
// Created by XinShuo Wang on 2021/11/2 9:19
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

TEST(leetcode_jz_60, 1) {
  using namespace std;
  class Solution {
    int count;
    map<int, int> m;

   public:
    vector<double> dicesProbability(int n) {
      work(n, 0);
      vector<double> ans;
      for (auto& kv : m) {
        ans.push_back(((double)(kv.second)) / count);
      }
      return ans;
    }

    void work(int n, int val) {
      if (n == 0) {
        if (m.find(val) == m.end())
          m[val] = 1;
        else
          m[val] += 1;
        count++;
        return;
      }
      for (int i = 0; i < 6; ++i) {
        work(n - 1, val + i);
      }
    }
  };
}

TEST(leetcode_jz_60, 2) {
  using namespace std;
  class Solution {
    map<pair<int, int>, int> cache;
    map<pair<int, int>, int>::iterator it;

   public:
    vector<double> dicesProbability(int n) {
      double sum = 0.0;
      vector<double> ans;
      for (int i = n; i <= 6 * n; ++i) {
        int t = work(n, i);
        sum += t;
        ans.push_back(t);
      }
      for (double& a : ans) a = a / sum;
      return ans;
    }

    int work(int n, int point) {
      if (point < n || point > 6 * n) return 0;
      if (n == 1) {
        if (point <= 6 && point >= 1) return 1;
        return 0;
      }
      if ((it = cache.find(make_pair(n, point))) != cache.end())
        return it->second;
      int ans = 0;
      for (int i = 1; i <= 6; ++i) {
        ans += work(n - 1, point - i);
      }
      cache[make_pair(n, point)] = ans;
      return ans;
    }
  };
}