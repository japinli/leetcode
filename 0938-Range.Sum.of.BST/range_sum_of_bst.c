/*----------------------------------------------------------------------------
 *
 * range_sum_of_bst.c
 *   Given the `root` node of a binary search tree, return the sum of
 *   values of all nodes with value between `L` and `R` (inclusive).
 *
 *   The binary search tree is guaranteed to have unique values.
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

int
rangeSumBST(struct TreeNode* root, int L, int R)
{
    int sum = 0;

    if (root == NULL) {
        return sum;
    }
    if (root->val >= L && root->val <= R) {
        sum += root->val;
    }

    sum += rangeSumBST(root->left, L, R);
    sum += rangeSumBST(root->right, L, R);

    return sum;
}
