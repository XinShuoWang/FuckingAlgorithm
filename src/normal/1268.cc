//
// Created by XinShuo Wang on 2021/8/22 19:28
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_1268, 1) {
  using namespace std;
  class Trie {
   private:
    struct Node {
      bool is_end_;
      Node* next[26];
      Node() {
        is_end_ = false;
        memset(next, 0, sizeof(next));
      }
    };
    Node root_;

    void dfs(string& prefix, Node* t, vector<string>& v, int& count) {
      if (count <= 0) return;
      if (t->is_end_) {
        count--;
        v.push_back(prefix);
      }
      for (int i = 0; i < 26; ++i) {
        prefix += char('a' + i);
        if (t->next[i] != nullptr) dfs(prefix, t->next[i], v, count);
        prefix.pop_back();
      }
    }

   public:
    void insert(string& s) {
      Node* t = &root_;
      for (char c : s) {
        if (t->next[c - 'a'] == nullptr) t->next[c - 'a'] = new Node();
        t = t->next[c - 'a'];
      }
      t->is_end_ = true;
    }

    vector<string> startWith(string& s) {
      Node* t = &root_;
      for (char c : s) {
        t = t->next[c - 'a'];
        if (t == nullptr) return vector<string>{};
      }
      vector<string> res;
      int count = 3;
      dfs(s, t, res, count);
      return res;
    }
  };

  class Solution {
   public:
    vector<vector<string>> suggestedProducts(vector<string>& products,
                                             string searchWord) {
      Trie trie;
      for (auto& product : products) {
        trie.insert(product);
      }
      vector<vector<string>> res;
      for (int i = 1; i <= searchWord.length(); ++i) {
        string sub = searchWord.substr(0, i);
        res.emplace_back(trie.startWith(sub));
      }
      return res;
    }
  };
}