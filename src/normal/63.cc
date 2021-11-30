//
// Created by XinShuo Wang on 2021/11/30 11:50
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

TEST(leetcode_63, 1) {
  using namespace std;
  class Solution {
    int ans;

   public:
    Solution() { ans = 0; }

    void dfs(vector<vector<int>>& grid, int m, int n, int x, int y) {
      if (x == m - 1 && y == n - 1) {
        ans++;
        return;
      }
      // down
      if (x + 1 < m && grid[x + 1][y] == 0) dfs(grid, m, n, x + 1, y);
      // right
      if (y + 1 < n && grid[x][y + 1] == 0) dfs(grid, m, n, x, y + 1);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
      if (grid[0][0] == 1) return 0;
      int m = grid.size(), n = grid[0].size();
      dfs(grid, m, n, 0, 0);
      return ans;
    }
  };
}

TEST(leetcode_63, 2) {
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
    int dfs(vector<vector<int>>& grid, int m, int n, int x, int y) {
      if (x == m - 1 && y == n - 1) return 1;
      if ((it = cache.find(combine(x, y))) != cache.end()) return it->second;
      int ans = 0;
      // down
      if (x + 1 < m && grid[x + 1][y] == 0) ans += dfs(grid, m, n, x + 1, y);
      // right
      if (y + 1 < n && grid[x][y + 1] == 0) ans += dfs(grid, m, n, x, y + 1);
      cache[combine(x, y)] = ans;
      return ans;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
      if (grid[0][0] == 1) return 0;
      int m = grid.size(), n = grid[0].size();
      return dfs(grid, m, n, 0, 0);
    }
  };
}