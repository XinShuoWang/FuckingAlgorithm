1. 刷题环境
   1. 编译器使用的是虚拟机里面的GCC 9，IDE使用CLion，CLion需要配置一下新建文件模板，参考下面：
      ```
      //
      // Created by XinShuo Wang on ${DATE} ${TIME}
      //
      #[[#include]]# <bits/stdc++.h>
      #[[#include]]# <gtest/gtest.h>
    
      TEST(leetcode_${FILE_NAME}, 1){
      using namespace std;
      }
      ```
   2. 使用gtest框架，将每一题当做一个测试用例来写，在用例之间是隔离的。
2. 解释
    - p开头的文件，例如`p1551.cc`就是洛谷的题目
    - 无标识的是Leetcode的题目
    - jz开头的是剑指offer的题目
    - m就是《程序员面试金典》的题目

3. 笔记
   - 递归思想
       - 大胆写初始条件

   - BFS算法
       - 使用队列辅助
       - 层序遍历就是BFS

   - DFS算法
     - 前序、中序、后序遍历其实就是DFS，这些遍历都是子节点为2时候的特殊情况
     - 前序就是先访问root，再去访问root->left，最后访问root->right；前序就是先访问root->left，再去访问root，最后访问root->right；
     - 遍历顺序不明白可以以一颗有3节点的平衡树举例子，左边遍历完了就要去找右边。

   - 最小生成树

   - 并查集
     - 创建merge（将两个的祖先节点之间进行合并）、find（找到祖先节点）方法，在find里面使用路径压缩

   - 线段树

   - 字典树
      - 本质就是26叉树（为什么是26叉？因为一共有26个字母）
      - 只有当指向子节点不为NULL的时候，这个值才确定（例子：`next[13]`不为NULL，则此节点可以取值`'a'+13`），所以也可以说字典树是用边来确定值的 
      - 需要注意使用isEnd变量来控制一个单词的结尾，这样在查找一个单词是否存在的时候就需要这个变量
      - 使用边来确定值，而不是使用点，举个例子，普通的树：`a--->b--->c`，字典树：`起始--a-->节点--b-->结束`
    
   - 滑动窗口算法
      - 窗口起始位置在移动，窗口大小也在变化

   - KMP算法
     - 搜索时的逻辑参考`src/review/28.cc`第3个用例
     - next数组创建的时候需要了解以下基本条件：
       - A的前缀子串与B的后缀子串要相等，要依次迭代才能求得j
       - A与B相等
     - next数组有两个作用：1.将匹配串移动到下一个匹配的位置。2.匹配串的指针进行移动，与主串进行对齐

   - Splay树

   - 动态规划
     - 先写递归（所以在这一步就要找到递推关系），然后再反着想去写迭代，当然也可以只用递归，这样有需要记忆表。

   - 回溯算法
     - 一般需要记录每一步的结果，最后把每一步的结果作为集合返回回去

   - 单调栈
     - 让栈里面得数据保持单调性，单调增或者单调减对于问题来说是可以暂时不求解的，等到单调性被打破才需要进行求解
