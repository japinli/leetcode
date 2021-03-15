/*----------------------------------------------------------------------------
 *
 * leaf_similar_trees.c
 *   Consider all the leaves of a binary tree, from left to right order, the
 *   values of those leaves form a leaf value sequence.
 *
 *   Two binary trees are considered leaf-similar if their leaf value
 *   sequence is the same.
 *
 *   Return `true` if and only if the two given trees with head nodes `root1`
 *   and `root2` are leaf-similar.
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

#define MAX_LEAF_NODES  200

static void
dfs(struct TreeNode *root, int *res, int *index)
{
    if (root == NULL) {
        return;
    }

    if (root->left == NULL && root->right == NULL) {
        res[(*index)++] = root->val;
        return;
    }

    dfs(root->left, res, index);
    dfs(root->right, res, index);
}
    
bool
leafSimilar(struct TreeNode* root1, struct TreeNode* root2)
{
    int leaves1[MAX_LEAF_NODES] = { 0 };
    int leaves2[MAX_LEAF_NODES] = { 0 };
    int index1 = 0;
    int index2 = 0;

    dfs(root1, leaves1, &index1);
    dfs(root2, leaves2, &index2);
    
    if (index1 != index2) {
        return false;
    }
    
    return memcmp(leaves1, leaves2, sizeof(int) * index1) == 0;
}