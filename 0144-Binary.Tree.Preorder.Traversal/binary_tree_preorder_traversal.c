/*----------------------------------------------------------------------------
 *
 * binary_tree_preorder_traversal.c
 *   Given a binary tree, return the preorder traversal of its nodes'
 *   values.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>


/* Definition for a binary tree node. */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

static int
getTreeNodesNum(struct TreeNode *root)
{
    if (root == NULL) {
        return 0;
    }

    return getTreeNodesNum(root->left) + getTreeNodesNum(root->right) + 1;
}

static int
preorderTraversalHelper(struct TreeNode *root, int *result, int index)
{
    if (root == NULL) {
        return index;
    }

    result[index++] = root->val;
    index = preorderTraversalHelper(root->left, result, index);
    index = preorderTraversalHelper(root->right, result, index);

    return index;
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *
preorderTraversal(struct TreeNode* root, int* returnSize)
{
    int *result;

    *returnSize = getTreeNodesNum(root);
    result = (int *) malloc(sizeof(int) * (*returnSize));

    preorderTraversalHelper(root, result, 0);

    return result;
}
