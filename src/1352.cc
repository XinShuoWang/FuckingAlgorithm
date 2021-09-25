//
// Created by XinShuo Wang on 2021/9/23 10:05
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_1352, 1) {
  using namespace std;
  class ProductOfNumbers {
    vector<int> v;

   public:
    void add(int num) {
      if (v.empty()) {
        if (num != 0) {
          v.push_back(num);
        }
      } else {
        if (num == 0) {
          v.clear();
        } else {
          v.push_back(v.back() * num);
        }
      }
    }

    int getProduct(int k) {
      if (k > v.size()) return 0;
      if (k == v.size()) return v.back();
      return v.back() / v[v.size() - k - 1];
    }
  };

  /**
   * Your ProductOfNumbers object will be instantiated and called as such:
   * ProductOfNumbers* obj = new ProductOfNumbers();
   * obj->add(num);
   * int param_2 = obj->getProduct(k);
   */

  ProductOfNumbers productOfNumbers;
  productOfNumbers.add(3);  // [3]
  productOfNumbers.add(0);  // [3,0]
  productOfNumbers.add(2);  // [3,0,2]
  productOfNumbers.add(5);  // [3,0,2,5]
  productOfNumbers.add(4);  // [3,0,2,5,4]
  productOfNumbers.getProduct(2);  // 返回 20 。最后 2 个数字的乘积是 5 * 4 = 20
  productOfNumbers.getProduct(
      3);  // 返回 40 。最后 3 个数字的乘积是 2 * 5 * 4 = 40
  productOfNumbers.getProduct(
      4);  // 返回  0 。最后 4 个数字的乘积是 0 * 2 * 5 * 4 = 0
  productOfNumbers.add(8);  // [3,0,2,5,4,8]
  productOfNumbers.getProduct(2);  // 返回 32 。最后 2 个数字的乘积是 4 * 8 = 32
}