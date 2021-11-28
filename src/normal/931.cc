//
// Created by XinShuo Wang on 2021/11/27 10:08
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

TEST(leetcode_931, 1) {
  using namespace std;
  class Solution {
    int ans;

   public:
    Solution() { ans = INT_MAX; }

    void dfs(vector<vector<int>>& matrix, int x, int y, int val) {
      if (x >= matrix.size()) {
        ans = min(ans, val);
        return;
      }
      if (y - 1 >= 0) dfs(matrix, x + 1, y - 1, val + matrix[x][y]);
      dfs(matrix, x + 1, y, val + matrix[x][y]);
      if (y + 1 < matrix[0].size())
        dfs(matrix, x + 1, y + 1, val + matrix[x][y]);
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
      for (int i = 0; i < matrix[0].size(); ++i) {
        dfs(matrix, 0, i, 0);
      }
      return ans;
    }
  };
}

TEST(leetcode_931, 2) {
  using namespace std;
  class Solution {
    unordered_map<int, int> cache;
    unordered_map<int, int>::iterator it;

    int combine(int x, int y) {
      int ans = x;
      ans <<= 16;
      ans += y;
      return ans;
    }

   public:
    int dfs(vector<vector<int>>& matrix, int x, int y) {
      if (x >= matrix.size()) return 0;
      if ((it = cache.find(combine(x, y))) != cache.end()) return it->second;
      int ans = INT_MAX;
      if (y - 1 >= 0) ans = min(ans, dfs(matrix, x + 1, y - 1) + matrix[x][y]);
      ans = min(ans, dfs(matrix, x + 1, y) + matrix[x][y]);
      if (y + 1 < matrix[0].size())
        ans = min(ans, dfs(matrix, x + 1, y + 1) + matrix[x][y]);
      cache[combine(x, y)] = ans;
      return ans;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
      int ans = INT_MAX;
      for (int i = 0; i < matrix[0].size(); ++i) {
        ans = min(ans, dfs(matrix, 0, i));
      }
      return ans;
    }
  };
}