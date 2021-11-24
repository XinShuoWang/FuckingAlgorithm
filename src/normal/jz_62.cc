//
// Created by XinShuo Wang on 2021/11/7 14:43
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

TEST(leetcode_jz_62, 1) {
  using namespace std;
  class CircleList {
    list<int> data;
    list<int>::iterator it;

   public:
    CircleList(int n) {
      for (int i = 0; i < n; ++i) {
        data.push_back(i);
      }
      it = data.begin();
    }

    int len() { return data.size(); }

    void del(int step) {
      auto t = it == data.end() ? data.begin() : it;
      while (step > 1) {
        t++;
        if (t == data.end()) t = data.begin();
        step--;
      }
      it = ++t;
      --t;
      // cout << *t << endl;
      data.erase(t);
    }

    int get() { return data.front(); }
  };

  class Solution {
   public:
    int lastRemaining(int n, int m) {
      CircleList circleList(n);
      while (circleList.len() != 1) {
        circleList.del(m);
      }
      return circleList.get();
    }
  };
}

TEST(leetcode_jz_62, 2) {
  using namespace std;
  class Solution {
   public:
    int lastRemaining(int n, int m) {
      vector<int> data(n, 0);
      for (int i = 0; i < n; ++i) {
        data[i] = i;
      }
      int idx = 0;
      while (data.size() > 1) {
        idx = (idx + m - 1) % n;
        data.erase(data.begin() + idx);
        n--;
      }
      return data.front();
    }
  };
}

TEST(leetcode_jz_62, 3) {
  using namespace std;
  class Solution {
   public:
    int lastRemaining(int n, int m) {
      int ans = 0;
      for (int i = 2; i <= n; ++i) {
        ans = (ans + m) % i;
      }
      return ans;
    }
  };
}