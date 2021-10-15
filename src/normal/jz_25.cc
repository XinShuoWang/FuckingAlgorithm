//
// Created by XinShuo Wang on 2021/10/14 12:36
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "ListNode.h"

TEST(leetcode_jz_25, 1) {
  using namespace std;
  class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      ListNode *a = l1, *b = l2;
      if (a == nullptr) return b;
      if (b == nullptr) return a;
      ListNode* ans = nullptr;
      if (a->val < b->val) {
        ans = a;
        a = a->next;
      } else {
        ans = b;
        b = b->next;
      }
      ListNode* move = ans;
      while (a != nullptr || b != nullptr) {
        if (a == nullptr) {
          move->next = b;
          break;
        }
        if (b == nullptr) {
          move->next = a;
          break;
        }
        if (a->val < b->val) {
          move->next = a;
          a = a->next;
          move = move->next;
        } else {
          move->next = b;
          b = b->next;
          move = move->next;
        }
      }
      return ans;
    }
  };
}