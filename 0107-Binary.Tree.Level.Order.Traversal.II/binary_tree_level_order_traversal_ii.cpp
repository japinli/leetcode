/*----------------------------------------------------------------------------
 *
 * binary_tree_level_order_traversal_ii.cpp
 *   Given a binary tree, return the bottom-up level order traversal of
 *   its nodes' values. (ie, from left to right, level by level from
 *   leaf to root).
 *
 *----------------------------------------------------------------------------
 */
#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> results;

    levelOrder(root, results, 0);
    reverse(results.begin(), results.end());
    return results;
  }

  void levelOrder(TreeNode *root, vector<vector<int>> &results, int level) {
    if (root == NULL) {
      return;
    }
    if (level >= results.size()) {
      results.push_back({});
    }
    results[level].push_back(root->val);

    levelOrder(root->left, results, level + 1);
    levelOrder(root->right, results, level + 1);
  }
};
