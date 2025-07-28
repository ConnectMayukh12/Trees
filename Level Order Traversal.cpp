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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)return {};
        queue<pair<int,TreeNode*>>q;
        q.push({1,root});
        vector<vector<int>> arr;
        int level,value;
        while(!q.empty()){
            auto element=q.front();
            q.pop();
            level=element.first;            
            TreeNode * ptr=element.second;

            
            value=element.second->val;
            
            if(arr.size()<level)arr.resize(level);
            arr[level-1].push_back(value);
        
            
            if(ptr->left)q.push({level+1,ptr->left});
            if(ptr->right)q.push({level+1,ptr->right});
            
        }
        
        return arr;
    }
};
