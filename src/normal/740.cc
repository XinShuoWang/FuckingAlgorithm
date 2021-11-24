//
// Created by XinShuo Wang on 2021/11/18 11:52
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

TEST(leetcode_740, 1) {
  using namespace std;
  class Solution {
    int ans;
    unordered_map<int, int> del;

   public:
    Solution() { ans = INT_MIN; }

    void work(int key) {
      if (del.find(key) == del.end())
        del[key] = 1;
      else
        del[key] += 1;
    }

    void dfs(vector<int>& nums, int v, int i) {
      if (i >= nums.size()) {
        ans = max(ans, v);
        return;
      }
      if (del.find(nums[i]) == del.end() || del[nums[i]] == 0) {
        work(nums[i] - 1), work(nums[i] + 1);
        dfs(nums, v + nums[i], i + 1);
        del[nums[i] - 1] -= 1, del[nums[i] + 1] -= 1;
      }
      dfs(nums, v, i + 1);
    }

    int deleteAndEarn(vector<int>& nums) {
      vector<bool> visited(nums.size(), false);
      dfs(nums, 0, 0);
      return ans;
    }
  };
}

TEST(leetcode_740, 2) {
  using namespace std;
  class Solution {
    unordered_map<int, int> cache;
    unordered_map<int, int>::iterator it;

   public:
    int dfs(vector<int>& data, int i) {
      if (i >= data.size()) return 0;
      if ((it = cache.find(i)) != cache.end()) return it->second;
      int ans = max(dfs(data, i + 2) + data[i], dfs(data, i + 1));
      cache[i] = ans;
      return ans;
    }

    int deleteAndEarn(vector<int>& nums) {
      sort(nums.begin(), nums.end(), [](int x, int y) { return x < y; });
      map<int, int> m;
      for (int& num : nums) {
        if (m.find(num) != m.end())
          m[num] += 1;
        else
          m[num] = 1;
      }
      vector<int> data;
      for (auto& kv : m) {
        data.push_back(kv.first * kv.second);
        if (m.find(kv.first + 1) == m.end()) data.push_back(0);
      }
      return dfs(data, 0);
    }
  };
}