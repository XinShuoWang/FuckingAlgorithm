//
// Created by XinShuo Wang on 2021/11/20 15:06
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

TEST(leetcode_918, 1) {
  using namespace std;
  class Solution {
   public:
    int maxSubarraySumCircular(vector<int>& nums) {
      if (nums.size() == 1) return nums[0];
      vector<int> v(2 * nums.size());
      for (int i = 0; i < 2 * nums.size(); ++i) {
        v[i] = nums[i % nums.size()];
      }
      for (int i = 1; i < v.size(); ++i) {
        v[i] += v[i - 1];
      }
      int ans = INT_MIN;
      for (int i = 0; i < v.size(); ++i) {
        for (int j = i + 1; j < min(v.size(), i + 1 + nums.size()); ++j) {
          ans = max(ans, v[j] - v[i]);
        }
      }
      return ans;
    }
  };
}

TEST(leetcode_918, 2) {
  using namespace std;
  class Solution {
   public:
    int maxSubarraySumCircular(vector<int>& nums) {
      if (nums.size() == 1) return nums[0];
      vector<int> v(nums), vv(nums);
      int a = nums[0];
      for (int i = 1; i < nums.size(); ++i) {
        if (v[i - 1] > 0) v[i] += v[i - 1];
        a = max(a, v[i]);
      }
      int b = nums[0];
      for (int i = 1; i < nums.size(); ++i) {
        if (vv[i - 1] < 0) vv[i] += vv[i - 1];
        b = min(b, vv[i]);
      }
      int c = nums[0], d = 0;
      for (int i = 1; i < nums.size(); ++i) {
        c = max(c, nums[i]);
        d += 2 * nums[i];
      }
      if (c < 0) return c;
      return a > (d - b) ? a : d - b;
    }
  };
}