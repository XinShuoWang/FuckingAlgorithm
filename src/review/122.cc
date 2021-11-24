//
// Created by XinShuo Wang on 2021/11/22 10:49
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

TEST(leetcode_122, 1) {
  using namespace std;
  class Solution {
    int ans;

   public:
    Solution() { ans = INT_MIN; }

    void dfs(vector<int>& prices, int step, bool cash, int pre, int val) {
      if (step >= prices.size()) {
        ans = max(ans, val);
        return;
      }
      if (cash) {
        dfs(prices, step + 1, false, prices[step], val);
        dfs(prices, step + 1, true, pre, val);
      } else {
        dfs(prices, step + 1, true, 0, val + (prices[step] - pre));
        dfs(prices, step + 1, false, pre, val);
      }
    }

    int maxProfit(vector<int>& prices) {
      dfs(prices, 0, true, 0, 0);
      return ans;
    }
  };
}

TEST(leetcode_122, 2) {
  using namespace std;
  class Solution {
    unordered_map<int64_t, int> cache;
    unordered_map<int64_t, int>::iterator it;
    int64_t work(int step, int pre) {
      int64_t ans = 0;
      ans += step;
      ans <<= 20;
      ans += pre;
      return ans;
    }

   public:
    int dfs(vector<int>& prices, int step, int pre) {
      if (step >= prices.size()) return 0;
      if ((it = cache.find(work(step, pre))) != cache.end()) return it->second;
      int ans;
      if (pre == -1) {
        ans = dfs(prices, step + 1, prices[step]);
        ans = max(ans, dfs(prices, step + 1, pre));
      } else {
        ans = dfs(prices, step + 1, -1) + (prices[step] - pre);
        ans = max(ans, dfs(prices, step + 1, pre));
      }
      cache[work(step, pre)] = ans;
      return ans;
    }

    int maxProfit(vector<int>& prices) { return dfs(prices, 0, -1); }
  };
}

TEST(leetcode_122, 3) {
  using namespace std;
  class Solution {
   public:
    int maxProfit(vector<int>& prices) {
      int n = prices.size();
      int dp[n][2];
      dp[0][0] = 0, dp[0][1] = -prices[0];
      for (int i = 1; i < n; ++i) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
      }
      return dp[n - 1][0];
    }
  };
}