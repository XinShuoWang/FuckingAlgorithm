//
// Created by XinShuo Wang on 2021/11/24 10:04
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

TEST(leetcode_714, 1) {
  using namespace std;
  class Solution {
   public:
    int maxProfit(vector<int>& prices, int fee) {
      const int n = prices.size();
      vector<vector<int>> dp(2, vector<int>(n, 0));
      // 为了方便计算收益，就把每日的price作为收益
      // 否则还需要计算差价
      dp[0][0] = 0, dp[1][0] = -prices[0];
      for (int i = 1; i < prices.size(); ++i) {
        // 第i天手里没有股票，
        dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] + prices[i] - fee);
        // 第i天手里有股票，
        dp[1][i] = max(dp[0][i - 1] - prices[i], dp[1][i - 1]);
      }
      return dp[n - 1][0];
    }
  };
}