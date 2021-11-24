//
// Created by XinShuo Wang on 2021/11/9 9:45
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

TEST(leetcode_jz_29, 1) {
  using namespace std;
  class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      int a = -1, b = matrix[0].size(), c = -1, d = matrix.size(), i = 0, j = 0;
      vector<int> ans;
      while (a != b && c != d) {
        while (j > a && j < b && i > c && i < d) {
          int val = matrix[i][j++];
          ans.push_back(val);
          //cout << "1," << val << endl;
        }
        // 第一列是缩小范围
        // 第二列是把多加（减）的补回来，防止超出边界
        // 第三列是防止重复打印
        ++c, --j, ++i;
        if(a == b && c == d) break;
        if(ans.size() == matrix[0].size() * matrix.size()) break;
        while (j > a && j < b && i > c && i < d) {
          int val = matrix[i++][j];
          ans.push_back(val);
          //cout << "2," << val << endl;
        }
        --b, --i, --j;
        if(a == b && c == d) break;
        if(ans.size() == matrix[0].size() * matrix.size()) break;
        while (j > a && j < b && i > c && i < d) {
          int val = matrix[i][j--];
          ans.push_back(val);
          //cout << "3," << val << endl;
        }
        --d, ++j, --i;
        if(a == b && c == d) break;
        if(ans.size() == matrix[0].size() * matrix.size()) break;
        while (j > a && j < b && i > c && i < d) {
          int val = matrix[i--][j];
          ans.push_back(val);
          //cout << "4," << val << endl;
        }
        ++a, ++i, ++j;
        if(a == b && c == d) break;
        if(ans.size() == matrix[0].size() * matrix.size()) break;
      }
      return ans;
    }
  };
}