//
// Created by XinShuo Wang on 2021/8/30 10:47
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "ListNode.h"

TEST(leetcode_82, 1) {
  using namespace std;
  class Solution {
   public:
    ListNode* deleteDuplicates(ListNode* head) {
      if (head == nullptr) return head;
      vector<ListNode*> v;
      while (head != nullptr) {
        bool del = false;
        ListNode* move = head->next;
        while (move != nullptr && move->val == head->val) {
          move = move->next;
          del = true;
        }
        if (del) {
          head = move;
        } else {
          v.push_back(head);
          head = head->next;
        }
      }
      switch (v.size()) {
        case 0:
          return nullptr;
        case 1:
          v[0]->next = nullptr;
          return v[0];
        default:
          for (int i = 0; i < v.size() - 1; ++i) {
            v[i]->next = v[i + 1];
            v[i + 1]->next = nullptr;
          }
          return v[0];
      }
    }
  };
}

TEST(leetcode_82, 2) {
  using namespace std;
  class Solution {
   public:
    ListNode* deleteDuplicates(ListNode* head) {
      if (head == nullptr) return head;
      ListNode *ans = nullptr, *next = nullptr;
      while (head != nullptr) {
        bool del = false;
        ListNode* move = head->next;
        while (move != nullptr && move->val == head->val) {
          move = move->next;
          del = true;
        }
        if (del) {
          head = move;
        } else {
          ListNode* temp = head->next;
          if (ans == nullptr) {
            ans = head;
            next = head;
            next->next = nullptr;
          } else {
            next->next = head;
            next = next->next;
            next->next = nullptr;
          }
          head = temp;
        }
      }
      return ans;
    }
  };
}