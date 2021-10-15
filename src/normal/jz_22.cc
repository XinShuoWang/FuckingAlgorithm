//
// Created by XinShuo Wang on 2021/10/13 9:56
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "ListNode.h"

TEST(leetcode_jz_22, 1) {
  using namespace std;
  class Solution {
   public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
      ListNode *a = head, *b = head;
      while (k > 0) {
        b = b->next;
        --k;
      }
      while (b != nullptr) {
        a = a->next;
        b = b->next;
      }
      return a;
    }
  };
}