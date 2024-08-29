/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
   stack<TreeNode*> s;

    void push_l_N_R(TreeNode* root){
        for(; root != nullptr; root = root->left){
            s.push(root);
        }
    }
    BSTIterator(TreeNode* root) {      
        push_l_N_R(root);
    }
    
    int next() {
        TreeNode* node = s.top();
        s.pop();

        push_l_N_R(node->right);
        return node->val;
        
    }
    
    bool hasNext() {

        return !s.empty();
        
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
