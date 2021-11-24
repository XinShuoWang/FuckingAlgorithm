//
// Created by XinShuo Wang on 2021/11/15 10:18
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

TEST(leetcode_1395, 1) {
  using namespace std;
  class Solution {
    vector<int> path;
    unordered_map<int64_t, int> cache;
    unordered_map<int64_t, int>::iterator it;

   public:
    int64_t make(int i) {
      int64_t ans = 0;
      switch (path.size()) {
        case 0:
          ans <<= 10;
          ans <<= 10;
          ans <<= 10;
          ans += i;
          break;
        case 1:
          ans += path[0];
          ans <<= 10;
          ans <<= 10;
          ans <<= 10;
          ans += i;
          break;
        case 2:
          ans += path[0];
          ans <<= 10;
          ans += path[1];
          ans <<= 10;
          ans <<= 10;
          ans += i;
          break;
        case 3:
          ans += path[0];
          ans <<= 10;
          ans += path[1];
          ans <<= 10;
          ans += path[2];
          ans <<= 10;
          ans += i;
          break;
      }
      return ans;
    }

    int work(vector<int>& rating, int i) {
      if (path.size() == 3) {
        if ((rating[path[0]] > rating[path[1]] && rating[path[1]] > rating[path[2]]) ||
            (rating[path[0]] < rating[path[1]] && rating[path[1]] < rating[path[2]])) {
          return 1;
        }
        return 0;
      }
      if (i >= rating.size()) return 0;
      if ((it = cache.find(make(i))) != cache.end()) return it->second;
      int ans = 0;
      path.push_back(i);
      ans += work(rating, i + 1);
      path.pop_back();
      ans += work(rating, i + 1);
      cache[make(i)] = ans;
      return ans;
    }

    int numTeams(vector<int>& rating) { return work(rating, 0); }
  };
}