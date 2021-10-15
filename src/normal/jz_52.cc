//
// Created by XinShuo Wang on 2021/10/14 12:36
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "ListNode.h"

TEST(leetcode_jz_52, 1) {
  using namespace std;
  class Solution {
   public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
      set<ListNode*> s;
      ListNode* move = headA;
      while (move != nullptr) {
        s.insert(move);
        move = move->next;
      }
      move = headB;
      while (move != nullptr) {
        if (s.find(move) != s.end()) return move;
        move = move->next;
      }
      return nullptr;
    }
  };
}