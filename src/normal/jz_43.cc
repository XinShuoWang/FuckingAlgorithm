//
// Created by XinShuo Wang on 2021/11/4 9:21
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

TEST(leetcode_jz_43, 1) {
  using namespace std;
  class Solution {
    int work(int n) {
      int ans = 0;
      while (n != 0) {
        if (n % 10 == 1) ans++;
        n /= 10;
      }
      return ans;
    }

   public:
    int countDigitOne(int n) {
      int ans = 0;
      for (int i = 1; i <= n; ++i) {
        ans += work(i);
      }
      return ans;
    }
  };
}

TEST(leetcode_jz_43, 2) {
  using namespace std;
  class Solution {
    int work(int n, int num) {
      long long high = n, low = 0, curr, digit = 1;
      while (num != 0) {
        low += (high % 10) * digit;
        high /= 10;
        digit *= 10;
        num--;
      }
      curr = high % 10;
      high /= 10;
      // cout << high << "," << curr << "," << low << "," << digit << endl;
      switch (curr) {
          // 比如对于数字21041
        case 0:
          // 在百位为0的时候，[00|01|02|...|20]041
          return high * digit;
        case 1:
          // 在千位为1的时候，[0|1]1[00|01|...|41]
          return high * digit + low + 1;
        default:
          // 在十位为4的时候，[000|001|...|210][10|11|12|...|19]
          return (high + 1) * digit;
      }
    }

   public:
    int countDigitOne(int n) {
      int nums = 0, ans = 0, m = n;
      while (n != 0) n /= 10, nums++;
      for (int i = 0; i < nums; ++i) {
        ans += work(m, i);
      }
      return ans;
    }
  };
}

TEST(leetcode_jz_43, 3) {
  using namespace std;
  class Solution {
   public:
    int countDigitOne(int n) {
      long long high = n / 10, cur = n % 10, low = 0, digit = 1, ans = 0;
      while (high != 0) {
        switch (cur) {
          case 0:
            ans += high * digit;
            break;
          case 1:
            ans += high * digit + low + 1;
            break;
          default:
            ans += (high + 1) * digit;
            break;
        }
        low += cur * digit;
        cur = high % 10;
        high /= 10;
        digit *= 10;
      }
      return ans;
    }
  };
}