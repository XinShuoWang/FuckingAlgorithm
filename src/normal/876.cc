//
// Created by XinShuo Wang on 2021/8/18 12:32
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "ListNode.h"

TEST(leetcode_876, 1) {
  using namespace std;
  class Solution {
   public:
    // 这题是经典的快慢指针用法，典型的双指针
    ListNode* middleNode(ListNode* head) {
      if (head->next == nullptr) return head;
      ListNode* next = head->next->next;
      while (next != nullptr && next->next != nullptr) {
        head = head->next;
        next = next->next->next;
      }
      return head->next;
    }
  };
}