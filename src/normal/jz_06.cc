//
// Created by XinShuo Wang on 2021/10/5 15:45
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "ListNode.h"

TEST(leetcode_jz_06, 1) {
  using namespace std;
  class Solution {
   public:
    vector<int> reversePrint(ListNode* head) {
      vector<int> ans;
      while (head != nullptr) {
        ans.push_back(head->val);
        head = head->next;
      }
      reverse(ans.begin(), ans.end());
      return ans;
    }
  };
}


TEST(leetcode_jz_06, 2) {
  using namespace std;
  class Solution {
   public:
    vector<int> reversePrint(ListNode* head) {
      vector<int> ans;
      work(ans, head);
      return ans;
    }

    void work(vector<int>& ans, ListNode* head) {
      if(head== nullptr) return;
      work(ans, head->next);
      ans.push_back(head->val);
    }
  };
}