//
// Created by XinShuo Wang on 2021/8/18 12:53
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "ListNode.h"

TEST(leetcode_19, 1) {
  using namespace std;
  class Solution {
   public:
    // 这个解法使用空间换时间，不用第二轮遍历
    // 还可以使用快慢指针来优化，快指针领先慢指针n个身位
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      vector<ListNode*> v;
      ListNode* t = head;
      while (t != nullptr) {
        v.push_back(t);
        t = t->next;
      }
      n = v.size() - n;
      if (n == 0) {
        return v[0]->next;
      } else if (n == v.size() - 1) {
        auto before = v[n - 1];
        before->next = nullptr;
      } else {
        auto before = v[n - 1];
        auto after = v[n + 1];
        before->next = after;
      }
      return v[0];
    }
  };
}