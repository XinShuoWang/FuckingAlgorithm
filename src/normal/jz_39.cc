//
// Created by XinShuo Wang on 2021/10/26 9:48
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

TEST(leetcode_jz_39, 1) {
  using namespace std;
  class Solution {
   public:
    int majorityElement(vector<int>& nums) {
      int size = nums.size();
      unordered_map<int, int> m;
      for (int num : nums) {
        if (m.find(num) != m.end()) {
          m[num] += 1;
          if (m[num] > size / 2) return num;
        } else {
          m[num] = 1;
          if (m[num] > size / 2) return num;
        }
      }
      return 0;
    }
  };
}

TEST(leetcode_jz_39, 2) {
  using namespace std;
  class Solution {
   public:
    int majorityElement(vector<int>& nums) {
      sort(nums.begin(), nums.end(), [](int a, int b) { return a < b; });
      return nums[nums.size() / 2];
    }
  };
}


TEST(leetcode_jz_39, 3) {
  using namespace std;
  class Solution {
   public:
    int majorityElement(vector<int>& nums) {
      while (true){
       int candidate = nums[rand() % nums.size()];
       int count = 0;
       for (int num : nums) {
         if(num==candidate) ++count;
       }
       if(count > nums.size() / 2) return candidate;
      }
    }
  };
}