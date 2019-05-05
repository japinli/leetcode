/*----------------------------------------------------------------------------
 *
 * maximum_depth_of_n-ary_tree.c
 *   Given a n-ary tree, find its maximum depth.
 *
 *   The maximum depth is the number of nodes along the longest path
 *   from the root node down to the farthest leaf node.
 *
 *----------------------------------------------------------------------------
 */

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution1 {
public:
    int maxDepth(Node *root) {
        int depth = 0;

        if (root == NULL) {
            return depth;
        }

        for (auto iter = root->children.begin();
             iter != root->children.end();
             ++iter) {
            int subdepth = maxDepth(*iter);

            if (subdepth > depth) {
                depth = subdepth;
            }
        }
        return depth + 1;
    }
};

class Solution {
public:
    int maxDepth(Node *root) {
        int depth = 0;
        queue<Node *> q;

        if (root == NULL) {
            return depth;
        }
        q.push(root);

        while (!q.empty()) {
            depth++;
            int size = q.size()
            for (int i = 0; i < size; i++) {
                Node *node = q.front(); q.pop();
                for (auto &child : node->children) {
                    if (child) {
                        q.push(child);
                    }
                }
            }
        }

        return depth;
    }
};
