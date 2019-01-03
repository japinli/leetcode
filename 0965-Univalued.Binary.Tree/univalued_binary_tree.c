/*----------------------------------------------------------------------------
 *
 * univalued_binary_tree.c
 *   A binary tree is `univalued` if every node in the tree has the same
 *   value.
 *
 *   Return true if and only if the given tree is univalued.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool
isUnivalTree(struct TreeNode *root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return true;
    }

    if (root->left && root->val != root->left->val) {
        return false;
    }

    if (root->right && root->val != root->right->val) {
        return false;
    }

    return isUnivalTree(root->left) && isUnivalTree(root->right);
}
