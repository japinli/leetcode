/*----------------------------------------------------------------------------
 *
 * n-ary_tree_preorder_traversal.c
 *   Given an `n-ary` tree, return the preorder traversal of its nodes'
 *   values.
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
    vector<int> preorder(Node* root) {
        vector<int> result;
        preorder(root, result);

        return result;
    }

    void preorder(Node *root, vector<int> &result) {
        if (root == NULL) {
            return;
        }

        result.push_back(root->val);
        for (vector<Node *>::iterator node = root->children.begin();
             node != root->children.end(); node++) {
            preorder(*node, result);
        }
    }
};

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> result(0);
        stack<Node *> mystack;

        if (root == NULL) {
            return result;
        }

        mystack.push(root);

        while (!mystack.empty()) {
            Node *t = mystack.top();
            mystack.pop();
            result.push_back(t->val);
            for (auto node = t->children.rbegin(); node != t->children.rend(); ++node) {
                if (*node != NULL) {
                    mystack.push(*node);
                }
            }

        }
        return result;
    }
};
