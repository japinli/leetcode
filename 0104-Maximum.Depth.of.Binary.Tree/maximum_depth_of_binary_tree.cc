/*----------------------------------------------------------------------------
 *
 * maximum_depth_of_binary_tree.cc
 *   Given the root of a binary tree, return its maximum depth.
 *
 *   A binary tree's maximum depth is the number of nodes along the
 *   longest path from the root node down to the farthest leaf node.
 *
 *----------------------------------------------------------------------------
 */

/* Definition of a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

#include <queue>
class Solution1 {
public:
    int maxDepth(TreeNode *root) {
        int depth = 0;
        std::queue<TreeNode *> queue;

        if (root == nullptr) {
            return 0;
        }

        queue.push(root);
        while (!queue.empty()) {
            depth++;

            size_t sz = queue.size();

            for (size_t i = 0; i < sz; i++) {
                TreeNode *current = queue.front();
                queue.pop();

                if (current->left) {
                    queue.push(current->left);
                }
                if (current->right) {
                    queue.push(current->right);
                }
            }
        }

        return depth;
    }
};
