# 剑指 Offer

---

## 面试题03. 数组中重复的数字

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof

### 难度

简单

### 题目描述

找出数组中重复的数字。

在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

### 示例 1：
```shell
输入：
[2, 3, 1, 0, 2, 5, 3]
输出：2 或 3 
```

### 限制：

```2 <= n <= 100000```

---

## 面试题04. 二维数组中的查找

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof

### 难度

简单

### 题目描述

在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

### 示例:

现有矩阵 matrix 如下：
```
[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
```

```
给定 target = 5，返回 true。
给定 target = 20，返回 false。
```

### 限制：

```0 <= n <= 1000```

```0 <= m <= 1000```

---

## 面试题05. 替换空格

### 难度

简单

### 题目描述

请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

### 示例 1：

```shell
输入：s = "We are happy."
输出："We%20are%20happy."
```

### 限制：

```0 <= s 的长度 <= 10000```

---

## 面试题06. 从尾到头打印链表

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof

### 难度

简单

### 题目描述

输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。
 

### 示例 1：

```shell
输入：head = [1,3,2]
输出：[2,3,1]
```

### 限制：

```0 <= 链表长度 <= 10000```

---

## 面试题07. 重建二叉树

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof

### 题目描述

输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

### 示例

例如，给出

```shell
前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
```

返回如下的二叉树：

```shell
    3
   / \
  9  20
    /  \
   15   7
```

### 限制：

```0 <= 节点个数 <= 5000```

---

## 面试题09. 用两个栈实现队列

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof

### 难度

简单

### 题目描述

用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )
 
### 示例 1：

```text
输入：
["CQueue","appendTail","deleteHead","deleteHead"]
[[],[3],[],[]]
输出：[null,null,3,-1]
```

### 示例 2：

```text
输入：
["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
[[],[],[5],[2],[],[]]
输出：[null,-1,null,null,5,2]
```

提示：

```
1 <= values <= 10000
最多会对 appendTail、deleteHead 进行 10000 次调用
```

---

## 面试题10- I. 斐波那契数列

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof

### 难度

简单

### 题目描述

写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项。斐波那契数列的定义如下：

```
F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
```
斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

### 示例 1：

```text
输入：n = 2
输出：1
```
### 示例 2：

```text
输入：n = 5
输出：5
```

### 提示：

```0 <= n <= 100```

---

## 面试题10- II. 青蛙跳台阶问题

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/qing-wa-tiao-tai-jie-wen-ti-lcof

### 难度

简单

### 题目描述

一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

### 示例 1：

```text
输入：n = 2
输出：2
```

### 示例 2：

```text
输入：n = 7
输出：21
```

### 提示：

```0 <= n <= 100```

---

## 面试题11. 旋转数组的最小数字

来源：力扣（LeetCode）

链接：https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof

### 难度

简单

### 题目描述

把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如，数组 ```[3,4,5,1,2]``` 为 ```[1,2,3,4,5]``` 的一个旋转，该数组的最小值为1。 

### 示例 1：

```shell
输入：[3,4,5,1,2]
输出：1
```

### 示例 2：
```shell
输入：[2,2,2,0,1]
输出：0
```

---

## 面试题40. 最小的k个数

### 难度

简单

### 题目描述

输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。

### 示例 1：

```
输入：arr = [3,2,1], k = 2
输出：[1,2] 或者 [2,1]
```

### 示例 2：

```
输入：arr = [0,1,2,1], k = 1
输出：[0]
```

### 限制：

```
0 <= k <= arr.length <= 10000
0 <= arr[i] <= 10000
```

---

## 面试题17. 打印从1到最大的n位数

### 难度

简单

### 题目描述

输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。

### 示例 1:

```
输入: n = 1
输出: [1,2,3,4,5,6,7,8,9]
```

### 说明：

```
用返回一个整数列表来代替打印
n 为正整数
```

---

## 面试题24. 反转链表

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof

### 难度

简单

### 题目描述

定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。

### 示例:

```
输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
```

### 限制：

```0 <= 节点个数 <= 5000```

---

## 面试题64. 求1+2+…+n

来源：LeetCode
链接：https://leetcode-cn.com/problems/qiu-12n-lcof

### 难度

中等

### 题目描述

求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

### 示例 1：

```
输入: n = 3
输出: 6
```

### 示例 2：

```
输入: n = 9
输出: 45
```

### 限制：

```1 <= n <= 10000```

---