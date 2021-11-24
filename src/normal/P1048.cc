//
// Created by XinShuo Wang on 2021/11/11 15:58
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

TEST(leetcode_P1048, 1) {
  using namespace std;
  class Solution {
   public:
    int N, W, value[100], weight[100], visited[100], ans = INT_MIN;

    void input() {
      cin >> W >> N;
      for (int i = 0; i < N; ++i) {
        cin >> weight[i] >> value[i];
        visited[i] = 0;
      }
    }

    bool ok() {
      for (int i = 0; i < N; ++i) {
        if (visited[i] == 0) return false;
      }
      return true;
    }

    void dfs(int x, int y) {
      if (ok()) {
        if (x <= W) ans = max(ans, y);
        return;
      }
      for (int i = 0; i < N; ++i) {
        if (visited[i] == 0) {
          visited[i] = 1;
          dfs(x, y);
          dfs(x + weight[i], y + value[i]);
          visited[i] = 0;
        }
      }
    }

    int main() {
      input();
      dfs(0, 0);
      cout << ans;
      return 0;
    }
  };
}

TEST(leetcode_P1048, 2) {
  using namespace std;
  class Solution {
   public:
    int N, W, value[100], weight[100];
    map<pair<int, int>, int> m;
    map<pair<int, int>, int>::iterator it;

    void input() {
      cin >> W >> N;
      for (int i = 0; i < N; ++i) {
        cin >> weight[i] >> value[i];
      }
    }

    int dfs(int w, int i) {
      if (i == N) return 0;
      if ((it = m.find(make_pair(w, i))) != m.end()) return it->second;
      int a = w - weight[i] >= 0 ? dfs(w - weight[i], i + 1) + value[i] : 0;
      int b = dfs(w, i + 1);
      m[make_pair(w, i)] = max(a, b);
      return max(a, b);
    }

    int main() {
      input();
      cout << dfs(W, 0);
      return 0;
    }
  };
}