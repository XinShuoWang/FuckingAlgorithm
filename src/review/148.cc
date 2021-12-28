//
// Created by XinShuo Wang on 2021/12/22 14:52
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "ListNode.h"

TEST(leetcode_148, 1) {
  using namespace std;
  class Solution {
   public:
    ListNode* sortList(ListNode* head) {
      if (head == nullptr) return nullptr;
      auto a = head;
      while (a != nullptr) {
        auto c = a->val;
        auto b = a->next, d = a;
        while (b != nullptr) {
          if (b->val < c) {
            c = b->val;
            d = b;
          }
          b = b->next;
        }
        int t = a->val;
        a->val = d->val;
        d->val = t;
        a = a->next;
      }
      return head;
    }
  };
}

TEST(leetcode_148, 2) {
  using namespace std;
  class Solution {
   public:
    ListNode* sortList(ListNode* head) {
      if (head == nullptr) return nullptr;
      vector<ListNode*> v;
      while (head != nullptr) {
        v.push_back(head);
        head = head->next;
      }
      sort(v.begin(), v.end(),
           [](ListNode* x, ListNode* y) { return x->val < y->val; });
      ListNode *ans = v[0], *move = ans;
      for (int i = 1; i < v.size(); ++i) {
        move->next = v[i];
        move = move->next;
      }
      move->next = nullptr;
      return ans;
    }
  };
}