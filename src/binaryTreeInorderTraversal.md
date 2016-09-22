[94. Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/)
===================================

原题
----

Given a binary tree, return the *inorder* traversal of its nodes' values.

For example:

Given binary tree `[1,null,2,3]`

```
      1
	   \
	    2
	   /
	  3
```

return `[1,3,2]`.

**Note:** Recursive solution is trivial, could you do it iteratively?


思路
----

1. 递归，最简单的方式，但不让使用。
2. 使用栈来模拟递归过程。

代码
----

思路1示例代码
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
	vector<int> inorderTraversal(TreeNode* root) {
		if (root == NULL) {
			return vector<int>();
		}
		
		vector<int> ret = inorderTraversal(root->left);
		ret.push_back(root->val);
		vector<int> right = inorderTraversal(root->right);
		
		ret.insert(ret.end(), right.begin(), right.end());
		
		return ret;
	}
};
```

思路2示例代码
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
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> ret;
		stack<TreeNode *> ss;
		
		if (root != NULL) {
			TreeNode *node = root;
			
			while (!ss.empty() || node != NULL) {
				while (node != NULL) {
					ss.push(node);
					node = node->left;
				}
				
				if (!ss.empty()) {
					TreeNode *p = ss.top();
					ss.pop();
					ret.push_back(p->val);
					node = p->right;
				}
			}
		}
		
		return ret;
	}
};
```
