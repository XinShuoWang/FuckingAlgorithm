//
// Created by XinShuo Wang on 2021/11/28 10:06
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

TEST(leetcode_120, 1) {
  using namespace std;
  class Solution {
    int ans;

   public:
    Solution() { ans = INT_MAX; }

    void dfs(vector<vector<int>>& triangle, int x, int y, int v) {
      if (x >= triangle.size()) {
        ans = min(ans, v);
        return;
      }
      if (y > triangle[x].size()) return;
      dfs(triangle, x + 1, y, v + triangle[x][y]);
      dfs(triangle, x + 1, y + 1, v + triangle[x][y]);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
      dfs(triangle, 0, 0, 0);
      return ans;
    }
  };
}

TEST(leetcode_120, 2) {
  using namespace std;
  class Solution {
   public:
    int dfs(vector<vector<int>>& triangle, int x, int y) {
      if (x >= triangle.size()) return 0;
      if (y > triangle[x].size()) return 0;
      int a = dfs(triangle, x + 1, y) + triangle[x][y];
      int b = dfs(triangle, x + 1, y + 1) + triangle[x][y];
      return min(a, b);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
      return dfs(triangle, 0, 0);
    }
  };
}

TEST(leetcode_120, 3) {
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
    int dfs(vector<vector<int>>& triangle, int x, int y) {
      if (x >= triangle.size()) return 0;
      if (y > triangle[x].size()) return 0;
      if ((it = cache.find(combine(x, y))) != cache.end()) return it->second;
      int a = dfs(triangle, x + 1, y) + triangle[x][y];
      int b = dfs(triangle, x + 1, y + 1) + triangle[x][y];
      cache[combine(x, y)] = min(a, b);
      return min(a, b);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
      return dfs(triangle, 0, 0);
    }
  };
}