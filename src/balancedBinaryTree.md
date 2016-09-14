[110. Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree/)
===========================

原题
----

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary
tree which the depth of the two subtrees of *every* node never differ
by more than 1.

题意
----

给定一个二叉树，判读其是否是高度平衡的。

对于这个问题，高度平衡的二叉树定义为二叉树中每个节点的两个子树的高度差
不超过1。

思路
----

1. 递归的判断每个节点的两个子树的高度差，出现不平衡时直接返回。该方法
   需要递归调用判断其子树的高度，同时，每个节点需要判断是否平衡，时间
   复杂度大致为`O(n^2)`。
2. 通过上面的思路，我们可以利用已有的信息，通过从下往上将节点的高度差
   累积到父节点上，若某个父节点出现不平衡则可直接返回，否则继续这个过
   程直到根节点为止。该方法的时间复杂度约为`O(n)`。

代码
----

思路1示例代码
```c++
class Solution {
public:
	bool isBalanced(TreeNode* root) {
		if (root == NULL || (root->left == NULL && root->right == NULL)) {
			return true;
		}
		
		int ldepth = binaryTreeDepth(root->left);
		int rdepth = binaryTreeDepth(root->right);
		
		if (abs(ldepth - rdepth) > 1) {
			return false;
		}
		
		if (isBalanced(root->left) == false || isBalanced(root->right) == false) {
			return false;
		}
		
		return true;
	}
	
	int binaryTreeDepth(TreeNode* root) {
		if (root == NULL) {
			return 0;
		}
		
		return 1 + max(binaryTreeDepth(root->left), binaryTreeDepth(root->right));
	}
};
```

思路2示例代码
```c++
class Solution {
public:
	bool isBalanced(TreeNode* root) {
		return checkDepth(root) == -1 ? false : true;
	}
	
	int checkDepth(TreeNode* root) {
		if (root == NULL) {
			return 0;
		}
		
		int left = checkDepth(root->left);
		if (left == -1) {
			return left;
		}
		
		int right = checkDepth(root->right);
		if (right == -1) {
			return right;
		}
		
		return abs(left - right) > 1 ? -1 : max(left, right) + 1;
	}
};
```
