/*----------------------------------------------------------------------------
 *
 * symmetric_tree.c
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <stdbool.h>

/*
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool
isSameSymmetricTree(struct TreeNode *l, struct TreeNode *r)
{
	if (l == NULL && r == NULL) {
		return true;
	} else if (l == NULL || r == NULL) {
		return false;
	}

	if (l->val == r->val) {
		return isSameSymmetricTree(l->left, r->right) &&
			isSameSymmetricTree(l->right, r->left);
	}

	return false;
}

bool
isSymmetric(struct TreeNode* root)
{
	return isSameSymmetricTree(root, root);
}
