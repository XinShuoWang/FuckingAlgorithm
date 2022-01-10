//
// Created by XinShuo Wang on 2022/1/2 13:49
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "ListNode.h"
#include "TreeNode.h"

TEST(leetcode_10, 1) {
  using namespace std;
  class Solution {
    struct GraphNode {
      int times_;
      char word_;
      bool must_;
      vector<GraphNode*> child_;
      GraphNode(int times, char word, bool must) {
        times_ = times;
        word_ = word;
        must_ = must;
      }
    };
    GraphNode* head;
    map<pair<GraphNode*, int>, bool> cache;
    map<pair<GraphNode*, int>, bool>::iterator it;

   public:
    Solution() { head = nullptr; }

    void buildGraph(string& p) {
      GraphNode* move = head;
      for (int i = 0; i < p.length(); ++i) {
        switch (p[i]) {
          case '.': {
            GraphNode* t;
            if (i + 1 < p.length() && p[i + 1] == '*') {
              t = new GraphNode(30, -1, false);
              t->child_.push_back(t), ++i;
            } else {
              t = new GraphNode(1, -1, true);
            }
            if (head == nullptr) {
              head = t;
            } else {
              move->child_.push_back(t);
            }
            move = t;
            break;
          }
          default: {
            GraphNode* t = nullptr;
            if (i + 1 < p.length() && p[i + 1] == '*') {
              t = new GraphNode(30, p[i], false);
              t->child_.push_back(t), ++i;
            } else {
              t = new GraphNode(1, p[i], true);
            }
            if (head == nullptr) {
              head = t;
            } else {
              move->child_.push_back(t);
            }
            move = t;
            break;
          }
        }
      }
      move->child_.push_back(nullptr);
      //   move = head;
      //   while(move != nullptr) {
      //       cout << move->word_ << "," << move->child_.size() << endl;
      //       switch(move->child_.size()){
      //           case 0:
      //             return;
      //           case 1:
      //             move = move->child_[0];
      //             break;
      //           case 2:
      //             if(move == move->child_[0]) move = move->child_[1];
      //             else move = move->child_[0];
      //             break;
      //       }
      //   }
    }

    bool dfs(GraphNode* node, string& s, int idx) {
      if ((it = cache.find(make_pair(node, idx))) != cache.end())
        return it->second;
      if (idx >= s.length() && node == nullptr) {
        cache[make_pair(node, idx)] = true;
        return true;
      } else if (idx >= s.length() && node != nullptr) {
        while (node != nullptr) {
          if (node->must_) {
            cache[make_pair(node, idx)] = false;
            return false;
          }
          switch (node->child_.size()) {
            case 0:
              cache[make_pair(node, idx)] = true;
              return true;
            case 1:
              node = node->child_[0];
              break;
            case 2:
              if (node == node->child_[0])
                node = node->child_[1];
              else
                node = node->child_[0];
              break;
          }
        }
        cache[make_pair(node, idx)] = true;
        return true;
      } else if (idx < s.length() && node != nullptr) {
        if (!node->must_) {
          for (auto t : node->child_) {
            if (t != node && dfs(t, s, idx)) {
              cache[make_pair(node, idx)] = true;
              return true;
            }
          }
        }
        if ((node->word_ == -1 || node->word_ == s[idx]) && node->times_ > 0) {
          node->times_ -= 1;
          for (auto t : node->child_) {
            if (dfs(t, s, idx + 1)) {
              cache[make_pair(node, idx)] = true;
              return true;
            }
          }
          node->times_ += 1;
        }
        cache[make_pair(node, idx)] = false;
        return false;
      } else if (idx < s.length() && node == nullptr) {
        cache[make_pair(node, idx)] = false;
        return false;
      }
      cache[make_pair(node, idx)] = false;
      return false;
    }

    bool isMatch(string& s, string& p) {
      buildGraph(p);
      return dfs(head, s, 0);
    }
  };
}