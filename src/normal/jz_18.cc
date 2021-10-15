//
// Created by XinShuo Wang on 2021/10/13 9:56
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "ListNode.h"

TEST(leetcode_jz_18, 1) {
  using namespace std;
  class Solution {
   public:
    ListNode* deleteNode(ListNode* head, int val) {
      if (head->val == val) return head->next;
      ListNode *move = head, *pre = nullptr;
      while (move->val != val) {
        pre = move;
        move = move->next;
      }
      pre->next = move->next;
      return head;
    }
  };
}