#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// Recursive Approach
class Solution
{
public:
    vector<int> ans;
    void In_Order(TreeNode *root)
    {
        if (!root)
            return;
        In_Order(root->left);
        ans.push_back(root->val);
        In_Order(root->right);
        return;
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        In_Order(root);
        return ans;
    }
};
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

// Iterative Approach
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> st;
        TreeNode *current = root;
        vector<int> ans;
        while (!st.empty() || current)
        {
            if (current)
            {

                st.push(current);

                current = current->left;
            }
            else
            {
                TreeNode *it = st.top();
                st.pop();
                ans.push_back(it->val);
                current = it->right;
            }
        }
        return ans;
    }
};

int main()
{
}