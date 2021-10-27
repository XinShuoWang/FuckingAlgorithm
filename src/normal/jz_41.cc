//
// Created by XinShuo Wang on 2021/10/24 19:55
//

/**
 *                             _ooOoo_
 *                            o8888888o
 *                            88" . "88
 *                            (| -_- |)
 *                            O\  =  /O
 *                         ____/`---'\____
 *                       .'  \\|     |//  `.
 *                      /  \\|||  :  |||//  \
 *                     /  _||||| -:- |||||-  \
 *                     |   | \\\  -  /// |   |
 *                     | \_|  ''\---/''  |   |
 *                     \  .-\__  `-`  ___/-. /
 *                   ___`. .'  /--.--\  `. . __
 *                ."" '<  `.___\_<|>_/___.'  >'"".
 *               | | :  `- \`.;`\ _ /`;.`/ - ` : | |
 *               \  \ `-.   \_ __\ /__ _/   .-` /  /
 *          ======`-.____`-.___\_____/___.-`____.-'======
 *                             `=---='
 *          ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
 *                     佛祖保佑        永无BUG
 *            佛曰:
 *                   写字楼里写字间，写字间里程序员；
 *                   程序人员写程序，又拿程序换酒钱。
 *                   酒醒只在网上坐，酒醉还来网下眠；
 *                   酒醉酒醒日复日，网上网下年复年。
 *                   但愿老死电脑间，不愿鞠躬老板前；
 *                   奔驰宝马贵者趣，公交自行程序员。
 *                   别人笑我忒疯癫，我笑自己命太贱；
 *                   不见满街漂亮妹，哪个归得程序员？
*/

#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include "TreeNode.h"
#include "ListNode.h"

TEST(leetcode_jz_41, 1){
using namespace std;
  class MedianFinder {
    list<int> data;
   public:
    /** initialize your data structure here. */
    MedianFinder() {
    }

    void addNum(int num) {
      if(data.empty()){
        data.push_back(num);
      }else{
        if(num < data.front()){
          data.push_front(num);
        }else if(num > data.back()){
          data.push_back(num);
        }else{
          auto it = data.begin();
          while (*it<num) ++it;

        }
      }
    }

    double findMedian() {
      int count = data.size() / 2;
      auto it = data.begin();
      while (count != 0){
        it++, count--;
      }
      if(data.size()%2==0){

      }else{

      }
    }
  };
}