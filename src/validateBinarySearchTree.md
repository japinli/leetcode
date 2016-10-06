[98. Valid Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/)
==============================

原题
----

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

* The left subtree of a node contains only nodes with keys **less than** the node's key.
* The right subtree of a node contains only nodes with keys **greater than** the node's key.
* Both the left and right subtrees must also be binary search trees.

**Example 1:**

```
     2
	/ \
   1   3
```

Binary tree `[2, 1, 3]`, return true.

**Example 2:**

```
     2
	/ \
   1   3
```

Binary tree `[1,2,3]`, return false.

思路
----

1. 按题中定义的二叉搜索树中序遍历是递增序列，因此，可以通过比较中序遍
   历前一个节点和后一个节点的大小判断给定的二叉树是否为有效的二叉搜索
   树。
   
代码
----

思路1示例代码
```c++
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		TreeNode* prev = NULL;
		return isValidBST(root, prev);
	}
	
	bool isValidBST(TreeNode* root, TreeNode* &prev) {
		if (root == NULL) {
			return true;
		}
		
		if (isValidBST(root->left, prev) == false) {
			return false;
		}
		
		if (prev != NULL && prev->val >= root->val) {
			return false;
		}
		
		prev = root;
		return isValidBST(root->right, prev);
	}
};
```
