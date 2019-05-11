/*----------------------------------------------------------------------------
 *
 * convert_sorted_array_to_binary_search_tree.c
 *   Given an array where elements are sorted in ascending order,
 *   convert it to a height balanced BST.
 *
 *   For this problem, a height-balanced binary tree is defined as a
 *   binary tree in
 *   which the depth of the two subtrees of _every_ node never differ by
 *   more than 1.
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

static struct TreeNode *
balancedBST(int *nums, int beg, int end)
{
    int mid;
    struct TreeNode *node;

    if (beg > end) {
        return NULL;
    }

    mid = beg + (end - beg) / 2;  /* NOTE: avoid overflow */
    node = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    node->val = nums[mid];
    node->left = balancedBST(nums, beg, mid - 1);
    node->right = balancedBST(nums, mid + 1, end);

    return node;
}

struct TreeNode *
sortedArrayToBST(int *nums, int numsSize)
{
    return balancedBST(nums, 0, numsSize - 1);
}
