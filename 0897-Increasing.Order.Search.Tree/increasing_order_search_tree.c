/*----------------------------------------------------------------------------
 *
 * increasing_order_search_tree.c
 *   Given a binary search tree, rearrange the tree in in-order so that
 *   the leftmost node in the tree is now the root of the tree, and
 *   every node has no left child and only 1 right child.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>

/* Definition for a binary tree node. */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

static struct TreeNode *
helper(struct TreeNode *root, struct TreeNode *new_root)
{
    if (root == NULL) {
        return new_root;
    }

    new_root = helper(root->left, new_root);
    new_root->right = root;
    new_root->right->left = NULL;
    return helper(root->right, new_root->right);
}

struct TreeNode *
increasingBST(struct TreeNode *root)
{
    struct TreeNode new_root;

    helper(root, &new_root);

    return new_root.right;
}
