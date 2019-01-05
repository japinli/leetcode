/*----------------------------------------------------------------------------
 *
 * search_in_a_binary_search_tree.c
 *   Given the root node of a binary search tree (BST) and a value. You
 *   need to find the node in the BST that the node's value equals the
 *   given value. Return the subtree rooted with that node. If such node
 *   doesn't exist, you should return NULL.
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

struct TreeNode *
searchBST(struct TreeNode *root, int val)
{
    if (root == NULL || root->val == val) {
        return root;
    }

    if (root->val < val) {
        return searchBST(root->right, val);
    }

    return searchBST(root->left, val);
}

struct TreeNode *
searchBST1(struct TreeNode *root, int val)
{
    while (root != NULL && root->val != val) {
        root = root->val < val ? root->right : root->left;
    }

    return root;
}
