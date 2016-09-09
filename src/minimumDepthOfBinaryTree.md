[111. Minimum Depth of Binary Tree](https://leetcode.com/problems/minimum-depth-of-binary-tree/)
===================================

原题
----

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from
the root node down to the nearest leaf node.

思路
----

1. 递归遍历左右子树寻找最短路径。需要注意的是当一个节点只有左子树或右
   子树时，该节点不是叶子节点，需要继续查找非空的子树中最短路径。
2. 通过按树的层次遍历，当遇到第一个叶子节点时，即是树中的最短路径。

代码
----

思路1示例代码
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
		}
		
		int left = minDepth(root->left);
		int right = minDepth(root->right);
		
		return (left == 0 || right == 0) ? left + right + 1 : min(left, right) + 1;
	}
 };
```

思路2示例代码
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
		}
		
		queue<TreeNode *> q;
		int depth = 0;
		
		q.push(root);
		while (q.empty() == false) {
			depth++;
			size_t sz = q.size();
			for (size_t i = 0; i < sz; ++i) {
				TreeNode* node = q.front();
				q.pop();
				if (node && node->left == NULL && node->right == NULL) {
					return depth;
				}
				
				if (node->left) {
					q.push(node->left);
				}
				if (node->right) {
					q.push(node->right);
				}
			}
		}
		
		return 0;
	}
 };
```
