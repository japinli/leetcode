/*----------------------------------------------------------------------------
 *
 * path_sum.c
 *   Given a binary tree and a sum, determine if the tree has a
 *   root-to-leaf path such that adding up all the values along the path
 *   equals the given sum.
 *
 *----------------------------------------------------------------------------
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool
hasPathSum1(struct TreeNode* root, int sum)
{
    int t;

    if (root == NULL) {
        return false;
    }

    if (root->left == NULL && root->right == NULL) {
        return root->val == sum;
    }

    t = sum - root->val;
    return hasPathSum(root->left, t) || hasPathSum(root->right, t);
}

static bool
helper(struct TreeNode *root, int sum, int path)
{
    if (root == NULL) {
        return false;
    }

    path += root->val;
    if (root->left == NULL && root->right == NULL) {
        return path == sum;
    }

    return helper(root->left, sum, path) || helper(root->right, sum, path);
}

bool
hasPathSum(struct TreeNode *root, int sum)
{
    return helper(root, sum, 0);
}
