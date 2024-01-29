/*----------------------------------------------------------------------------
 *
 * binary_tree_level_order_traversal.cc
 *    Given the root of a binary tree, return the level order traversal
 *    of its nodes' values. (i.e., from left to right, level by level).
 *
 *----------------------------------------------------------------------------
 */
#include <vector>
#include <queue>

using namespace std;


/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res;

        if (root == nullptr) {
            return res;
        }

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            vector<int> values;
            vector<TreeNode *> tmp;

            while (!q.empty()) {
                tmp.push_back(q.front());
                q.pop();
            }

            for (auto n : tmp) {
                values.push_back(n->val);
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
            }

            res.push_back(values);
        }

        return res;
    }

    vector<vector<int>> levelOrder2(TreeNode *root) {
        vector<vector<int>> res;

        if (root == nullptr) {
            return res;
        }

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            vector<int> nums;

            auto size = q.size();
            for (auto i = 0; i < size; i++) {
                TreeNode *n = q.front();
                q.pop();

                nums.push_back(n->val);
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
            }

            res.push_back(nums);
        }

        return res;
    }
};
