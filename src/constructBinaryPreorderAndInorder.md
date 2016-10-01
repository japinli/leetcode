[105. Construct Binary Tree from Preorder and Inorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)
================================================================

原题
----

Given preorder and inorder traversal of a tree, construct the binary tree.

**Note:**

You may assume that duplicates do not exist in the tree.

思路
----

1. 采用递归，首先建立根节点，然后递归建立左右子树。

代码
----

思路1示例代码
```c
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
	if (preorderSize == 0 || inorderSize == 0) {
		return NULL;
	}
	
	struct TreeNode* root = malloc(sizeof(struct TreeNode));
	root->val = preorder[0];
	
	int idx = 0;
	while (idx < inorderSize) {
		if (preorder[0] == inorder[idx]) {
			break;
		}
		idx++;
	}
	
	root->left = buildTree(preorder + 1, idx, inorder, idx);
	root->right = buildTree(preorder + idx + 1, preorderSize - idx - 1, inorder + idx + 1, inorderSize - idx - 1);

	return root;
}
```
