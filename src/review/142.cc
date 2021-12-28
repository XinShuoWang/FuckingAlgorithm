//
// Created by XinShuo Wang on 2021/12/21 14:18
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "ListNode.h"

TEST(leetcode_142, 1) {
  using namespace std;
  class Solution {
   public:
    ListNode* detectCycle(ListNode* head) {
      set<ListNode*> s;
      while (head != nullptr) {
        if (s.find(head) != s.end())
          return head;
        else
          s.insert(head);
        head = head->next;
      }
      return nullptr;
    }
  };
}

TEST(leetcode_142, 2) {
  using namespace std;
  class Solution {
   public:
    ListNode* detectCycle(ListNode* head) {
      if (head == nullptr) return nullptr;
      auto a = head, b = head->next;
      while (true) {
        if (a == b) {
          auto c = head;
          while (a != c) {
            a = a->next;
            c = c->next;
          }
          return c;
        }
        if (a == nullptr || b == nullptr || b->next == nullptr) return nullptr;
        a = a->next;
        b = b->next->next;
      }
      return nullptr;
    }
  };
}