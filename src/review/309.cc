//
// Created by XinShuo Wang on 2021/11/24 9:49
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

TEST(leetcode_309, 1) {
  using namespace std;
  class Solution {
    int ans;

   public:
    Solution() { ans = 0; }

    void dfs(vector<int>& prices, int step, int pre, int val) {
      if (step >= prices.size()) {
        ans = max(ans, val);
        return;
      }
      if (pre == -1) {
        dfs(prices, step + 1, prices[step], val);
        dfs(prices, step + 1, pre, val);
      } else {
        dfs(prices, step + 2, -1, val + (prices[step] - pre));
        dfs(prices, step + 1, pre, val);
      }
    }

    int maxProfit(vector<int>& prices) {
      dfs(prices, 0, -1, 0);
      return ans;
    }
  };
}

TEST(leetcode_309, 2) {
  using namespace std;
  class Solution {
   public:
    int dfs(vector<int>& prices, int step, int pre) {
      if (step >= prices.size()) return 0;
      int a, b;
      if (pre == -1) {
        a = dfs(prices, step + 1, prices[step]);
        b = dfs(prices, step + 1, pre);
      } else {
        a = dfs(prices, step + 2, -1) + (prices[step] - pre);
        b = dfs(prices, step + 1, pre);
      }
      return max(a, b);
    }

    int maxProfit(vector<int>& prices) { return dfs(prices, 0, -1); }
  };
}

TEST(leetcode_309, 3) {
  using namespace std;
  class Solution {
    unordered_map<int64_t, int> cache;
    unordered_map<int64_t, int>::iterator it;
    int64_t combine(int step, int pre) {
      int64_t ans = step;
      ans <<= 32;
      ans += pre;
      return ans;
    }

   public:
    int dfs(vector<int>& prices, int step, int pre) {
      if (step >= prices.size()) return 0;
      if ((it = cache.find(combine(step, pre))) != cache.end())
        return it->second;
      int a, b;
      if (pre == -1) {
        a = dfs(prices, step + 1, prices[step]);
        b = dfs(prices, step + 1, pre);
      } else {
        a = dfs(prices, step + 2, -1) + (prices[step] - pre);
        b = dfs(prices, step + 1, pre);
      }
      cache[combine(step, pre)] = max(a, b);
      return max(a, b);
    }

    int maxProfit(vector<int>& prices) { return dfs(prices, 0, -1); }
  };
}