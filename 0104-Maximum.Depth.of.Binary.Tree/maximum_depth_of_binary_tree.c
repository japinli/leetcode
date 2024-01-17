/*----------------------------------------------------------------------------
 *
 * maximum_depth_of_binary_tree.c
 *   Given the root of a binary tree, return its maximum depth.
 *
 *   A binary tree's maximum depth is the number of nodes along the
 *   longest path from the root node down to the farthest leaf node.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>

/* Definition of a binary tree node. */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#define MAX(a, b)    ((a) > (b) ? (a) : (b))

int
maxDepth(struct TreeNode *root)
{
    if (root == NULL) {
        return 0;
    }

    /*
     * Do not call maxDepth() inside MAX macro, because it might be cause
     * Time Limit Exceeded.
     */
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);

    return MAX(l, r) + 1;
}
