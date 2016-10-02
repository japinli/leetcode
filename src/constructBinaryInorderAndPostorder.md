[106. Construct Binary Tree from Inorder and Postorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/)
=================================================================

原题
----

Given inorder and postorder traversal of a tree, construct the binary tree.

**Note:**

You may assume that duplicates do not exist in the tree.

思路
----

1. 类似于[105][]，采用递归解决该问题。

代码
----

思路1示例代码
```c
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
	if (inorderSize == 0 || postorderSize == 0) {
		return NULL;
	}
	
	struct TreeNode* root = malloc(sizeof(struct TreeNode));
	root->val = postorder[postorderSize - 1];
	
	int idx = 0;
	while (idx < inorderSize) {
		if (inorder[idx] == postorder[postorderSize - 1]) {
			break;
		}
		idx++;
	}
	
	root->left = buildTree(inorder, idx, postorder, idx);
	root->right = buildTree(inorder + idx + 1, inorderSize - idx - 1, postorder + idx, postorderSize - idx - 1);
	
	return root;
}
```

[105]: src/constructBinaryPreorderAndInorder.md
