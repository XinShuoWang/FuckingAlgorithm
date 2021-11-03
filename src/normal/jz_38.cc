//
// Created by XinShuo Wang on 2021/11/1 12:08
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

TEST(leetcode_jz_38, 1) {
  using namespace std;
  class Solution {
    string path;
    set<string> ans;
    bool visited[8];

   public:
    Solution() {
      for (bool& i : visited) {
        i = false;
      }
    }

    vector<string> permutation(string& s) {
      work(s);
      vector<string> res(ans.begin(), ans.end());
      return res;
    }

    bool ok(string& s) {
      for (int i = 0; i < s.length(); ++i) {
        if (!visited[i]) return true;
      }
      return false;
    }

    void work(string& s) {
      if (!ok(s)) {
        ans.insert(path);
        return;
      }
      for (int i = 0; i < s.length(); ++i) {
        if (!visited[i]) {
          visited[i] = true;
          path.push_back(s[i]);
          work(s);
          path.pop_back();
          visited[i] = false;
        }
      }
    }
  };
}