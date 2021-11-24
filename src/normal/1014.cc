//
// Created by XinShuo Wang on 2021/11/22 9:54
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

TEST(leetcode_1014, 1) {
  using namespace std;
  class Solution {
   public:
    int maxScoreSightseeingPair(vector<int>& values) {
      int ans = INT_MIN;
      for (int i = 0; i < values.size(); ++i) {
        for (int j = i + 1; j < values.size(); ++j) {
          ans = max(ans, values[i] + values[j] + i - j);
        }
      }
      return ans;
    }
  };
}

TEST(leetcode_1014, 2) {
  using namespace std;
  class Solution {
   public:
    int maxScoreSightseeingPair(vector<int>& values) {
      vector<int> v(values);
      int val = INT_MIN;
      for (int i = 0; i < v.size(); ++i) {
        v[i] = max(v[i] + i, val);
      }
      int ans = INT_MIN;
      for (int i = 0; i < v.size(); ++i) {
        ans = max(ans, v[i] - i);
      }
      return ans;
    }
  };
}