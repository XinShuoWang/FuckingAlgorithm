//
// Created by XinShuo Wang on 2021/9/12 9:54
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_139, 1) {
  using namespace std;
  class Tree {
    struct Node {
      bool is_end;
      Node* next[26];
      Node() {
        is_end = false;
        for (auto& n : next) {
          n = nullptr;
        }
      }
    };
    Node* root;

   public:
    Tree() : root(nullptr) {}

    void build(vector<string>& v) {
      for (auto& i : v) {
        add(i);
      }
    }

    void add(string& s) {
      if (root == nullptr) root = new Node();
      Node* move = root;
      for (char c : s) {
        if (move->next[c - 'a'] == nullptr) move->next[c - 'a'] = new Node();
        move = move->next[c - 'a'];
      }
      move->is_end = true;
    }

    bool exist(string& s) {
      Node* move = root;
      for (char c : s) {
        if (move == nullptr) return false;
        move = move->next[c - 'a'];
      }
      return move != nullptr && move->is_end;
    }
  };

  class Solution {
    Tree tree;

   public:
    bool wordBreak(string s, vector<string>& wordDict) {
      tree.build(wordDict);
      return work(s, 0);
    }

    bool work(string& s, int start) {
      if (start == s.length()) return true;
      for (int i = start + 1; i <= s.length(); ++i) {
        string sub_str = s.substr(start, i - start);
        if (tree.exist(sub_str) && work(s, i)) {
          return true;
        }
      }
      return false;
    }
  };
}

TEST(leetcode_139, 2) {
  using namespace std;
  class Solution {
    unordered_set<string> ss;

   public:
    bool wordBreak(string s, vector<string>& wordDict) {
      ss.insert(wordDict.begin(), wordDict.end());
      return work(s, 0);
    }

    bool work(string& s, int start) {
      if (start == s.length()) return true;
      for (int i = start + 1; i <= s.length(); ++i) {
        string sub_str = s.substr(start, i - start);
        if (ss.find(sub_str) != ss.end() && work(s, i)) {
          return true;
        }
      }
      return false;
    }
  };
}