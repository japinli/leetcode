/*----------------------------------------------------------------------------
 *
 * sum_of_root_to_leaf_binary_numbers.c
 *   You are given the `root` of a binary tree where each node has a value
 *   `0` or `1`.  Each root-to-leaf path represents a binary number starting
 *   with the most significant bit.  For example, if the path is
 *   `0 -> 1 -> 1 -> 0 -> 1`, then this could represent `01101` in binary,
 *   which is `13`.
 *
 *   For all leaves in the tree, consider the numbers represented by the path
 *   from the root to that leaf.
 *
 *   Return the sum of these numbers. The answer is __guaranteed__ to fit in
 *   a __32-bits__ integer.
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

static int
helper(struct TreeNode *root, int sum)
{
    if (root == NULL) {
        return 0;
    }

    sum = (sum << 1) | root->val;
    if (root->left == NULL && root->right == NULL) {
        return sum;
    }

    return helper(root->left, sum) + helper(root->right, sum);
}

int
sumRootToLeaf(struct TreeNode *root)
{
    return helper(root, 0);
}
