//
// Created by XinShuo Wang on 2021/9/17 8:56
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "ListNode.h"

TEST(leetcode_23, 1) {
  using namespace std;
  struct Data {
    int val;
    ListNode* self;
    Data() {
      val = 0;
      self = nullptr;
    }

    Data(int val, ListNode* self) {
      this->val = val;
      this->self = self;
    }

    bool operator<(Data b) const { return val > b.val; }
  };
  class Solution {
   public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      priority_queue<Data> q;
      for (auto& head : lists) {
        if (head != nullptr) q.push(Data(head->val, head));
      }
      ListNode *ans = nullptr, *move = nullptr;
      while (!q.empty()) {
        if (move == nullptr) {
          move = q.top().self;
          ans = move;
        } else {
          move->next = q.top().self;
          move = move->next;
        }
        ListNode* next = q.top().self->next;
        q.pop();
        if (next != nullptr) q.push(Data(next->val, next));
      }
      return ans;
    }
  };
}