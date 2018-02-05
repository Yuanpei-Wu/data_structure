# 数据结构代码与注释
## kmp模式匹配算法
### 说明
关键是得到部分匹配表next[]，即子串前缀和后缀的最长公共匹配字符数组成的数组  
### 求取next[]
关键是递归k=next[k]  
令k=next[K]  ，若t[j]==t[k] 则最长前缀后缀长度又可以++ 作为next[K+1] ，若不等于，则next[K+1]不可能超过next[K]，所以下一步要到0到next[K]之间寻找。如何寻找呢？令k=next[next[K]] ，再次比较t[j]==t[k]  这样就形成递归   

## bst 二叉搜索树
### 说明
二叉搜索树的类，相关算法可以纳入其中  
### 思路
根据输入序列的有序度来选择采用何种方式生成树？  
### todo list

* Gen BST From In/Pre/Post Order Array 
* Delete Node
* Balance
