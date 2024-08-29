/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void helper(Node* root, Node* parent) {
        if (root == NULL)
            return;
        if (parent != NULL)
            parent->left->next = parent->right;
        if (parent != NULL and parent->next != NULL)
            parent->right->next = parent->next->left;
        if (root->left == NULL and root->right == NULL)
            return;
        helper(root->left, root);
        helper(root->right, root);
    }
    Node* connect(Node* root) {
        helper(root, NULL);
        return root;
    }
};
