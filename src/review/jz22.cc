//
// Created by XinShuo Wang on 2021/9/2 9:33
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "ListNode.h"

TEST(leetcode_jz22, 1) {
  using namespace std;
  class Solution {
   public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
      int len = 0;
      ListNode* ans = head;
      while (ans != nullptr) {
        ans = ans->next;
        len++;
      }
      ans = head;
      while (len - k > 0) {
        len--;
        ans = ans->next;
      }
      return ans;
    }
  };
}

TEST(leetcode_jz22, 2) {
  using namespace std;
  class Solution {
   public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
      ListNode* ans = nullptr;
      work(head, ans, k);
      return ans;
    }

    void work(ListNode* head, ListNode*& ans, int& k) {
      if (head == nullptr) return;
      work(head->next, ans, k);
      if (--k == 0) ans = head;
    }
  };
}

TEST(leetcode_jz22, 3) {
  using namespace std;
  class Solution {
   public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
      ListNode* ans = head;
      while (k-- > 0) ans = ans->next;
      return work(head, ans);
    }

    ListNode* work(ListNode* node1, ListNode* node2) {
      if (node2 == nullptr) return node1;
      return work(node1->next, node2->next);
    }
  };
}