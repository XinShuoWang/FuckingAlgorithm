//
// Created by XinShuo Wang on 2021/10/5 15:58
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "ListNode.h"

TEST(leetcode_jz_24, 1) {
  using namespace std;
  class Solution {
   public:
    ListNode* reverseList(ListNode* head) {
      if (head == nullptr) return nullptr;
      if (head->next == nullptr) return head;
      ListNode* ans = reverseList(head->next);
      head->next->next = head;
      head->next = nullptr;
      return ans;
    }
  };
}