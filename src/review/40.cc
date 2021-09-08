//
// Created by XinShuo Wang on 2021/9/8 9:32
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_40, 1) {
  using namespace std;
  class Solution {
    set<vector<int>> s;
    vector<int> path;

   public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      sort(candidates.begin(), candidates.end());
      work(candidates, target, 0);
      return vector<vector<int>>{s.begin(), s.end()};
    }

    void work(vector<int>& candidates, int target, int idx) {
      if (target == 0) {
        s.insert(path);
        return;
      }
      if (target < 0 || idx >= candidates.size()) return;
      work(candidates, target, idx + 1);
      path.push_back(candidates[idx]);
      work(candidates, target - candidates[idx], idx + 1);
      path.pop_back();
    }
  };
}

TEST(leetcode_40, 2) {
  using namespace std;
  class Solution {
    vector<vector<int>> ans;
    vector<int> path;

   public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      // 相对于39题，多了：数组内元素可重复，为了避免这种情况
      // 的出现[2,3,2],[3,2,2]所以要排序
      sort(candidates.begin(), candidates.end());
      work(candidates, target, 0);
      return ans;
    }

    void work(vector<int>& candidates, int target, int idx) {
      if (target < 0) return;
      if (target == 0) {
        ans.push_back(path);
        return;
      }
      for (int i = idx; i < candidates.size(); ++i) {
        // 等到第二次进入这个循环的时候而且相同就应该剪枝
        /*这个避免重复当思想是在是太重要了。
         * 这个方法最重要的作用是，可以让同一层级，不出现相同的元素。即
         *        1
         *       / \
         *      2   2  这种情况不会发生 但是却允许了不同层级之间的重复即
         *     /     \
         *    5       5
         *    例2
         *        1
         *       /
         *      2      这种情况确是允许的
         *     /
         *    2
         *    为何会有这种神奇的效果呢？
         *    首先 cur-1 == cur 是用于判定当前元素是否和之前元素相同的语句。这个语句就能砍掉例1。
         *    可是问题来了，如果把所有当前与之前一个元素相同的都砍掉，那么例二的情况也会消失。
         *    因为当第二个2出现的时候，他就和前一个2相同了。
         *    那么如何保留例2呢？
         *    那么就用cur > begin 来避免这种情况，你发现例1中的两个2是处在同一个层级上的，
         *    例2的两个2是处在不同层级上的。
         *    在一个for循环中，所有被遍历到的数都是属于一个层级的。我们要让一个层级中，
         *    必须出现且只出现一个2，那么就放过第一个出现重复的2，但不放过后面出现的2。
         *    第一个出现的2的特点就是 cur == begin. 第二个出现的2 特点是cur > begin.
         *    */
        if (i > idx && candidates[i] == candidates[i - 1]) continue;
        path.push_back(candidates[i]);
        // 这里不可以重复利用，所以是i+1而不是i
        work(candidates, target - candidates[i], i + 1);
        path.pop_back();
      }
    }
  };
}