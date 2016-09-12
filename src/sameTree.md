[100. Same Tree](https://leetcode.com/problems/same-tree/)
================

原题
----

Given two binary trees, write a function to check if they are equal or
not.

Two binary trees are considered equal if they are structurally
identical and the nodes have the smae value.

思路
----

递归判断。

代码
----

```c++
/**
 * Definition for a binary tree node. 
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == NULL && q == NULL) {
			return true;
		} else if (p == NULL || q == NULL) {
			return false;
		}
		
		if (p->val != q->val) {
			return false;
		}
		
		if (isSameTree(p->left, q->left) == false) {
			return false;
		}
		
		return isSameTree(p->right, q->right);
	}
	
};
```
