//
// Created by XinShuo Wang on 2021/11/29 10:48
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

TEST(leetcode_304, 1) {
  using namespace std;
  class NumMatrix {
    vector<vector<int>> v, vv;

   public:
    NumMatrix(vector<vector<int>>& matrix) {
      int m = matrix.size(), n = matrix[0].size();
      vv = matrix;
      v.resize(m + 1, vector<int>(n + 1, 0));
      for (int i = 1; i < m + 1; ++i) {
        for (int j = 1; j < n + 1; ++j) {
          v[i][j] = vv[i - 1][j - 1];
        }
      }
      for (int i = 1; i < m + 1; ++i) {
        for (int j = 2; j < n + 1; ++j) {
          v[i][j] += v[i][j - 1];
        }
      }
      for (int i = 2; i < m + 1; ++i) {
        for (int j = 1; j < n + 1; ++j) {
          v[i][j] += v[i - 1][j];
        }
      }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
      if (row1 == row2 && col1 == col2) return vv[row1][col1];
      return v[row2][col2] - v[row1 - 1][col2] - v[row2][col1 - 1] +
             v[row1 - 1][col1 - 1];
    }
  };
}