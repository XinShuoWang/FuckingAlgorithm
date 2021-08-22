//
// Created by XinShuo Wang on 2021/8/22 15:28
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_208, 1) {
  using namespace std;
  class Trie {
   private:
    bool isEnd;
    Trie* next[26];

   public:
    Trie() {
      isEnd = false;
      memset(next, 0, sizeof(next));
    }

    void insert(string word) {
      Trie* node = this;
      for (char c : word) {
        if (node->next[c - 'a'] == NULL) {
          node->next[c - 'a'] = new Trie();
        }
        node = node->next[c - 'a'];
      }
      node->isEnd = true;
    }

    bool search(string word) {
      Trie* node = this;
      for (char c : word) {
        node = node->next[c - 'a'];
        if (node == NULL) {
          return false;
        }
      }
      return node->isEnd;
    }

    bool startsWith(string prefix) {
      Trie* node = this;
      for (char c : prefix) {
        node = node->next[c - 'a'];
        if (node == NULL) {
          return false;
        }
      }
      return true;
    }
  };
}

TEST(leetcode_208, 2) {
  using namespace std;
  class Trie {
   private:
    struct Node {
      bool isEnd;
      Node* next[26];
    };
    Node root;

   public:
    /** Initialize your data structure here. */
    Trie() {
      root.isEnd = true;
      memset(root.next, 0, sizeof(root.next));
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
      Node* t = &root;
      for (char c : word) {
        if (t->next[c - 'a'] == nullptr) {
          t->next[c - 'a'] = new Node();
        }
        t = t->next[c - 'a'];
      }
      t->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
      Node* t = &root;
      for (char c : word) {
        t = t->next[c - 'a'];
        if (t == nullptr) return false;
      }
      return t->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given
     * prefix. */
    bool startsWith(string prefix) {
      Node* t = &root;
      for (char c : prefix) {
        t = t->next[c - 'a'];
        if (t == nullptr) return false;
      }
      return true;
    }
  };
}