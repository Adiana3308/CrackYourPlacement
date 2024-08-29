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
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        if(root==nullptr ) return sum;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        while(!q.empty()){
                auto node=q.front();
                q.pop();
                if(node==nullptr){
                    if(!q.empty()) q.push(nullptr);
                }
                else{
                    if(node->left){
                    q.push(node->left);
                    auto node1=node->left;
                    if(node1->left==nullptr && node1->right==nullptr) sum+=node->left->val;
                }
                if(node->right) q.push(node->right);
            }
        }
        return sum;
    }
};
