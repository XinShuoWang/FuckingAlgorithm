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
    - mt开头的是美团公司的面试题目

3. 标准库函数
    - 判断字母（不区分大小写）：isalpha(); 大写字母：isupper(); 小写字母：islower(); 数字：isdigit(); 字母和数字：isalnum();
    - min_element()、min_element()得到容器内最值
    - accumulate用来在容器内求和
    - set容器是用红黑树实现的，因此是有序的，可以使用begin()得到最小的元素，rbegin()得到最大的元素。
    - sort()函数可以进行快速排序，需要注意排序规则，可以自定义比较函数当做参数传入第三个参数，默认排序规则是这样：`[](int a, int b){ return a < b; }`，没有`=`。
    - atoi()可以将字符串转整数，itoa()可以将整数转字符串，atof()可以将字符串转float
    - binary_search()可以进行二分查找
    

4. 笔记
   - 递归思想
       - 大胆写初始条件
       - 对待二维数组的时候要注意区分第一维和第二维，和数学里的xOy不是对应关系

   - BFS算法
       - 使用队列辅助
       - 层序遍历就是BFS
       - 图的BFS就比树的多了一个判别是否访问过这个步骤，因为树是无环的所以不需要判别
       - 设置visited要尽早，因为这样可以减少进入队列的元素数目（防止重复）

   - DFS算法
     - 前序、中序、后序遍历其实就是DFS，这些遍历都是子节点为2时候的特殊情况
     - 前序就是先访问root，再去访问root->left，最后访问root->right；前序就是先访问root->left，再去访问root，最后访问root->right；
     - 遍历顺序不明白可以以一颗有3节点的平衡树举例子，左边遍历完了就要去找右边。

   - 最短路算法
     - 单源点最短路
       - 求一个固定的起点到各个顶点的最短路径
       - 下面的有无负权边仅仅是能不能检测负权边，都不能处理负权边
       - 有负权边
         - SPFA算法
         - Bellman-Ford算法：以边为单位进行遍历，检测是否可以通过遍历到的边来缩短路径，要进行`点的数目-1`次所有边的松弛操作，其实就可以看做Floyd算法的简化，因为Floyd针对的是多源点，而对每个节点使用一次Bellman-Ford算法就是Floyd算法了
       - 无负权边
         - Dijkstra算法
     - 多源点最短路
       - 求得出任意两个顶点之间的最短路径
       - Floyd算法：能不能经由k点，把i到j的距离缩短？代码：```dist[j][l] = min(dist[j][l], dist[j][i] + dist[i][l]); ```

   - 最小生成树

   - 并查集
     - 创建merge（将两个的祖先节点之间进行合并）、find（找到祖先节点）方法，在find里面使用路径压缩

   - 字典树
      - 本质就是26叉树（为什么是26叉？因为一共有26个字母）
      - 只有当指向子节点不为NULL的时候，这个值才确定（例子：`next[13]`不为NULL，则此节点可以取值`'a'+13`），所以也可以说字典树是用边来确定值的 
      - 需要注意使用isEnd变量来控制一个单词的结尾，这样在查找一个单词是否存在的时候就需要这个变量
      - 使用边来确定值，而不是使用点，举个例子，普通的树：`a--->b--->c`，字典树：`起始--a-->节点--b-->结束`
    
   - 滑动窗口算法
      - 窗口起始位置在移动，窗口大小也可以变化
    
   - 差分数组、前缀和
      - 差分数组：差分数组的第i个数即为原数组的第i−1个元素和第i个元素的差值，特别的：第0个数和原数组中的第0个数一样，差分数组记录的其实就是相对于前一个记录的增量
      - 前缀和：数组`a: [1,2,3,4,5]`的前缀和数组为：`prefix_sum:[1,3,6,10,15]`，规则为：`prefix_sum[i]=sum(0, i)`
      - 对差分数组求前缀和即可求得原数组

   - KMP算法
     - 搜索时的逻辑参考`src/review/28.cc`第3个用例
     - next数组创建的时候需要了解以下基本条件：
       - A的前缀子串与B的后缀子串要相等，要依次迭代才能求得j
       - A与B相等
     - next数组有两个作用：1.将匹配串移动到下一个匹配的位置。2.匹配串的指针进行移动，与主串进行对齐

   - 动态规划
     - 先写递归（所以在这一步就要找到递推关系），然后再反着想去写迭代，当然也可以只用递归，这样有需要记忆表。
     - 一般需要写有返回值的work函数，这样才能每一步都产生一个值，保存这个值就可以对搜索剪枝
     - 最好还是走迭代动态规划而不是递归+记忆化

   - 回溯算法
     - 一般需要记录每一步的结果，最后把每一步的结果作为集合返回回去

   - 单调栈
     - 让栈里面得数据保持单调性，单调增或者单调减对于问题来说是可以暂时不求解的，等到单调性被打破才需要进行求解
