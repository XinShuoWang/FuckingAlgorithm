//
// Created by XinShuo Wang on 2021/8/15 19:17
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_28, 1) {
  using namespace std;
  class Solution {
   public:
    int strStr(string haystack, string needle) {
      int n = haystack.size(), m = needle.size();
      if (m == 0) {
        return 0;
      }
      vector<int> pi(m);
      for (int i = 1, j = 0; i < m; i++) {
        while (j > 0 && needle[i] != needle[j]) {
          j = pi[j - 1];
        }
        if (needle[i] == needle[j]) {
          j++;
        }
        pi[i] = j;
      }
      for (int i = 0, j = 0; i < n; i++) {
        while (j > 0 && haystack[i] != needle[j]) {
          j = pi[j - 1];
        }
        if (haystack[i] == needle[j]) {
          j++;
        }
        if (j == m) {
          return i - m + 1;
        }
      }
      return -1;
    }
  };

  Solution solution;
  string a = "bbcddgh", b = "bcdd";
  cout << solution.strStr(a, b) << endl;
}

TEST(leetcode_28, 2) {
  using namespace std;
  class Solution {
    vector<int> next;

   public:
    void buildNext(string& str) {
      next.resize(str.length());
      for (int i = 1, j = 0; i < str.length(); i++) {
        while (j > 0 && str[i] != str[j]) {
          j = next[j - 1];
        }
        if (str[i] == str[j]) {
          j++;
        }
        next[i] = j;
      }
    }

    int search(string& str1, string& str2) {
      for (int i = 0, j = 0; i < str1.length(); i++) {
        while (j > 0 && str1[i] != str2[j]) {
          j = next[j - 1];
        }
        if (str1[i] == str2[j]) {
          j++;
        }
        if (j == str2.length()) {
          return i - str2.length() + 1;
        }
      }
      return -1;
    }

    int strStr(string haystack, string needle) {
      buildNext(needle);
      return search(haystack, needle);
    }
  };

  Solution solution;
  string a = "abeababeabf", b = "abeabf";
  cout << solution.strStr(a, b) << endl;
}

TEST(leetcode_28, 3) {
  using namespace std;
  class Solution {
    vector<int> next;

   public:
    void buildNext(string& str) {
      next.push_back(0);
      // i一直负责在前面“走”,j负责计算next具体的值
      int i = 1, j = 0;
      while (i < str.length()) {
        // 递推关系第一种：两者相等，直接+1就好
        if (str[i] == str[j]) {
          i++, j++;
          next.push_back(j);
        } else {
          /*
           *    A              B
           * (a b c) c  ... (a b c) d
           * 上述就是不相等的情况，因为c与d不匹配，所以要将j进行缩小这样才有可能得到正确的j
           *
           * 为什么要缩小j？
           * 此时A=B但是c!=d所以导致不匹配，这个j不能用，所以要进一步缩小j
           *
           * 我们要干什么？
           * 找到一个小一点的j使得B的后缀子串能够与A的前缀子串相等（只有这两个相等才能去
           * 讨论A的前缀子串的后一个字符是不是d）
           *
           * 满足条件的最大的j是多少呢？
           * 要满足：A的长度非j的前缀子串==B的长度非j的后缀子串，因为A=B，所以为j=p[now-1]
           *
           * 如下图，长度为now的子串A和子串B是`P[0]~P[x-1]`中最长的公共前后缀。
           * 可惜A右边的字符和B右边的那个字符不相等，`next[x]`不能改成
           * now+1了。因此，我们应该缩短这个now，
           * 把它改成小一点的值，再来试试`P[x]`是否等于`P[now]`。now该缩小到多少呢？
           * 显然，我们不想让now缩小太多。
           * 因此我们决定，在保持"`P[0]~P[x-1]`的now-前缀仍然等于now-后缀"的前提下，让这个
           * 新的now尽可能大一点。
           * `P[0]~P[x-1]`的公共前后缀，前缀一定落在串A里面、后缀一定落在串B里面。换句话
           * 讲：接下来now应该改成：
           * 使得
           * A的k-前缀等于B的k-后缀的最大的k。您应该已经注意到了一个非常强的性质——串A和
           * 串B是相同的！
           * B的后缀等于A的后缀！因此，使得A的k-前缀等于B的k-后缀的最大的k，其实就是
           * 串A的最长公共前后缀的
           * 长度 —— `next[now-1]`！
           *
           * https://z3.ax1x.com/2021/08/18/fTsCs1.jpg
           *
           */

          // 如果不相等，则要不断缩小j的值，期待在缩短之后可以得到j的正确值
          if (j == 0) {
            // 最终j回退到了开头，这就是结果了
            next.push_back(0);
            i++;
          } else {
            // 这是不匹配，然后要缩小j，next[j - 1]就是能够满足要求的最大的j
            j = next[j - 1];
          }
        }
      }
    }

    int search(string& str1, string& str2) {
      buildNext(str2);
      int i = 0, j = 0;
      // 循环一直到主串结束
      while (i < str1.length()) {
        if (str1[i] == str2[j]) {
          // 如果两个字符相等，那就继续往下进行匹配
          i++;
          j++;
        } else {
          // 这里出现了不匹配的字符
          if (j == 0) {
            // 如果在匹配串的开头就“错配”，那就直接将主串指针右移就好
            ++i;
          } else {
            // 不是在匹配串的开头“错配”，那就使用next数组的性质进行j的状态转移
            j = next[j - 1];
          }
        }
        // 如果j指针到了匹配串的尾部，那证明匹配成功，直接返回即可
        if (j == str2.length()) return i - j;
      }
      return -1;
    }

    int strStr(string haystack, string needle) {
      return search(haystack, needle);
    }
  };

  Solution solution;
  string a = "abeababeabf", b = "abeabf";
  cout << solution.strStr(a, b) << endl;
}

TEST(leetcode_28, 4) {
  using namespace std;
  class Solution {
   public:
    int strStr(string haystack, string needle) {
      const int m = haystack.size(), n = needle.size();
      if (n == 0) return 0;
      vector<int> pi(n);
      for (int i = 0, j = 1; j < n; j++) {
        while (i > 0 && needle[i] != needle[j]) i = pi[i - 1];
        if (needle[i] == needle[j]) i++;
        pi[j] = i;
      }
      for (int i = 0, j = 0; i < m; i++) {
        while (j > 0 && haystack[i] != needle[j]) j = pi[j - 1];
        if (haystack[i] == needle[j]) j++;
        if (j == n) return i - n + 1;
      }
      return -1;
    }
  };
}