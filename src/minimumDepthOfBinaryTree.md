[111. Minimum Depth of Binary Tree](https://leetcode.com/problems/minimum-depth-of-binary-tree/)
===================================

原题
----

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from
the root node down to the nearest leaf node.

思路
----

递归遍历左右子树寻找最短路径。需要注意的是当一个节点只有左子树或右子树
时，该节点不是叶子节点，需要继续查找非空的子树中最短路径。

代码
----

```C++
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
 	int minDepth(TreeNode* root) {
		if (root == NULL) {
			return 0;
		} else if (root->left == NULL && root->right == NULL) {
			return 1;
		}
		
		if (root->left == NULL && root->right != NULL) {
			return 1 + minDepth(root->right);
		} else if (root->left != NULL && root->right == NULL) {
			return 1 + minDepth(root->left);
		}
		
		return min(minDepth(root->left), minDepth(root->right)) + 1;
	}
 };
```
