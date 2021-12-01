//
// Created by XinShuo Wang on 2021/12/1 10:09
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

TEST(leetcode_221, 1) {
  using namespace std;
  class Solution {
   public:
    int maximalSquare(vector<vector<char>>& matrix) {
      int m = matrix.size(), n = matrix[0].size();
      vector<vector<int>> v(m + 1, vector<int>(n + 1, 0));
      for (int i = 0; i < m; ++i) {
        int val = (matrix[i][0] - '0');
        for (int j = 0; j < n; ++j) {
          if(j != 0) val += (matrix[i][j] - '0');
          v[i + 1][j + 1] = val + v[i][j + 1];
          // cout << "(" << val << "," << v[i][j + 1] << ")";
          // cout << v[i + 1][j + 1] << ',';
        }
        // cout << endl;
      }
      auto get = [&](int x1, int y1, int x2, int y2) {
        if(x1 == x2 && y1 == y2) return matrix[x1][y1] - '0';
        int ans = v[x2 + 1][y2 + 1] - v[x1][y2 + 1] - v[x2 + 1][y1] + v[x1][y1];
        //cout << x1 << "," << y1 << ";" << x2 << "," << y2 << ";" << ans << endl;
        return ans;
      };
      auto can = [&](int m, int n, int x, int y, int size) {
        return x + size - 1 < m && y + size - 1 < n &&
               get(x, y, x + size - 1, y + size - 1) == size * size;
      };
      int ans = 0;
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          while (can(m, n, i, j, ans + 1)) ans += 1;
        }
      }
      return ans * ans;
    }
  };
}