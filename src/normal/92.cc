//
// Created by XinShuo Wang on 2021/12/28 13:51
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "ListNode.h"
#include "TreeNode.h"

TEST(leetcode_92, 1) {
  using namespace std;
  class Solution {
   public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
      if (left == right) return head;
      vector<ListNode*> v;
      v.reserve(505);
      while (head != nullptr) v.push_back(head), head = head->next;
      reverse(v.begin() + left - 1, v.begin() + right);
      for (int i = 0; i < v.size() - 1; ++i) v[i]->next = v[i + 1];
      v[v.size() - 1]->next = nullptr;
      return v[0];
    }
  };
}

TEST(leetcode_92, 2) {
  using namespace std;
  class Solution {
   public:
    tuple<ListNode*, ListNode*> reverseList(ListNode* start, ListNode* end) {
      ListNode *curr = start, *before = nullptr, *after = curr->next;
      while (curr != end) {
        curr->next = before;
        before = curr;
        curr = after;
        after = curr->next;
      }
      curr->next = before;
      return make_tuple(end, start);
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
      if (left == right) return head;
      ListNode *a = head, *b = head, *before = nullptr, *after = nullptr;
      while (right - left > 0) b = b->next, after = b->next, right--;
      while (left > 1)
        before = a, a = a->next, b = b->next, after = b->next, left--;
      auto [c, d] = reverseList(a, b);
      if (before != nullptr && after != nullptr) {
        before->next = c, d->next = after;
        return head;
      } else if (before != nullptr && after == nullptr) {
        before->next = c;
        return head;
      } else if (before == nullptr && after != nullptr) {
        d->next = after;
        return c;
      } else if (before == nullptr && after == nullptr) {
        return c;
      }
      return nullptr;
    }
  };
}