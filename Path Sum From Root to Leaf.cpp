//https://leetcode.com/problems/path-sum/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        queue<pair<TreeNode*, int>> q;
        if (!root)
            return false;
        q.push({root, root->val});
        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int value = q.front().second;
            q.pop();
            if (!(node->left) && !(node->right)) {
                if ((value) == targetSum)
                    return true;
            }
            if (node->left)
                q.push({node->left, value + (node->left->val)});
            if (node->right)
                q.push({node->right, value + (node->right->val)});
        }
        return false;
    }
};
