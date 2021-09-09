//
// Created by XinShuo Wang on 2021/9/9 17:36
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "ListNode.h"

TEST(leetcode_83, 1) {
  using namespace std;
  class Solution {
   public:
    ListNode* deleteDuplicates(ListNode* head) {
      if (head == nullptr) return nullptr;
      vector<ListNode*> v;
      v.push_back(head);
      ListNode* move = head->next;
      while (move != nullptr) {
        if (move->val != v.back()->val) v.push_back(move);
        move = move->next;
      }
      ListNode* ans = v[0];
      move = ans;
      for (int i = 1; i < v.size(); ++i) {
        move->next = v[i];
        move = move->next;
        move->next = nullptr;
      }
      return ans;
    }
  };
}

TEST(leetcode_83, 2) {
  using namespace std;
  class Solution {
   public:
    ListNode* deleteDuplicates(ListNode* head) {
      if (head == nullptr) return nullptr;
      ListNode *ans = head, *prev = head, *move = head->next;
      ans->next = nullptr;
      while (move != nullptr) {
        if (move->val != prev->val) {
          prev->next = move;
          prev = prev->next;
          ListNode* t = move->next;
          prev->next = nullptr;
          move = t;
        } else {
          move = move->next;
        }
      }
      return ans;
    }
  };
}