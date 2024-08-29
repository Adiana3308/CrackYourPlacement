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
    map<int, vector<int>> mpp;
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<pair<TreeNode *, int>> visited;
        visited.push({root, 0});
        visited.push({nullptr, 0});
        recurse(visited);
        for(auto ar: mpp) {
            ans.push_back(ar.second);
        }
        return ans;
    }

    void recurse(queue<pair<TreeNode *, int>> &visited) {
        vector<pair<int,int>> currArr; 
        while(!visited.empty()) {
            pair<TreeNode *, int> curr = visited.front(); visited.pop();
            if(curr.first) {
                currArr.push_back({curr.first->val, curr.second});
                if(curr.first->left) visited.push({curr.first->left, curr.second-1});
                if(curr.first->right) visited.push({curr.first->right, curr.second+1});
            } else {
                if(!visited.empty()) visited.push({nullptr, 0});
                sort(currArr.begin(), currArr.end());
                for(auto k: currArr) {
                    mpp[k.second].push_back(k.first);
                }
                currArr.clear();
            }
        }
        return;
    }
};
