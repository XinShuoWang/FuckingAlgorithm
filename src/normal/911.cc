//
// Created by XinShuo Wang on 2021/12/11 12:11
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_911, 1) {
  using namespace std;
  class TopVotedCandidate {
    map<int, int> m1, m2;

   public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
      unordered_map<int, int> c;
      for (int i = 0; i < times.size(); ++i) {
        if (c.find(persons[i]) == c.end()) {
          c[persons[i]] = 1;
          m1[1] = persons[i];
        } else {
          c[persons[i]] += 1;
          m1[c[persons[i]]] = persons[i];
        }
        m2[times[i]] = m1.rbegin()->second;
      }
    }

    int q(int t) {
      while (m2.find(t) == m2.end()) t--;
      return m2.find(t)->second;
    }
  };

  /**
   * Your TopVotedCandidate object will be instantiated and called as such:
   * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
   * int param_1 = obj->q(t);
   */
}