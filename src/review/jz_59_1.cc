//
// Created by XinShuo Wang on 2021/11/5 9:35
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

TEST(leetcode_jz_59_1, 1) {
  using namespace std;
  class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      vector<int> ans;
      if (nums.empty()) return ans;
      for (int i = 0; i <= nums.size() - k; ++i) {
        int val = nums[i];
        for (int j = i + 1; j < i + k; ++j) val = max(val, nums[j]);
        ans.push_back(val);
      }
      return ans;
    }
  };
}

TEST(leetcode_jz_59_1, 2) {
  using namespace std;
  class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      if (nums.empty()) return vector<int>{};
      // 窗口个数
      vector<int> res(nums.size() - k + 1);
      deque<int> queue;
      // 遍历数组中元素，right表示滑动窗口右边界
      for (int right = 0; right < nums.size(); right++) {
        // 如果队列不为空且当前考察元素大于等于队尾元素，则将队尾元素移除。
        // 直到，队列为空或当前考察元素小于新的队尾元素
        while (!queue.empty() && nums[right] >= nums[queue.back()])
          queue.pop_back();
        // 存储元素下标
        queue.push_back(right);
        // 计算窗口左侧边界
        int left = right - k + 1;
        // 当队首元素的下标小于滑动窗口左侧边界left时
        // 表示队首元素已经不再滑动窗口内，因此将其从队首移除
        if (queue.front() < left) queue.pop_front();
        // 由于数组下标从0开始，因此当窗口右边界right+1大于等于窗口大小k时
        // 意味着窗口形成。此时，队首元素就是该窗口内的最大值
        if (right + 1 >= k) res[left] = nums[queue.front()];
      }
      return res;
    }
  };
}

TEST(leetcode_jz_59_1, 3) {
  using namespace std;
  class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      if (nums.empty()) return vector<int>{};
      vector<int> ans;
      deque<int> q;
      for (int i = 0; i < k; ++i) {
        while (!q.empty() && nums[i] > q.back()) q.pop_back();
        q.push_back(nums[i]);
      }
      ans.push_back(q.front());
      for (int i = k; i < nums.size(); ++i) {
        if (q.front() == nums[i - k]) q.pop_front();
        while (!q.empty() && nums[i] > q.back()) q.pop_back();
        q.push_back(nums[i]);
        ans.push_back(q.front());
      }
      return ans;
    }
  };
}