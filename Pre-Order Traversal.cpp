#include <bits/stdc++.h>
using namespace std;
// Recursive Approach

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    vector<int> ans;
    void PreOrder(TreeNode *root)
    {
        if (root == nullptr)
            return;
        ans.push_back(root->val);
        PreOrder(root->left);
        PreOrder(root->right);
        return;
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        PreOrder(root);
        return ans;
    }
};

// Iterative Approach
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        TreeNode *current = root;
        stack<TreeNode *> st;
        vector<int> res;
        while (current || !st.empty())
        {
            if (current)
            {
                res.push_back(current->val);
                st.push(current->right);
                current = current->left;
            }
            else
            {
                current = st.top();
                st.pop();
            }
        }
        return res;
    }
};
// Iterative Better Approach
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
            return ans;

        stack<TreeNode *> st;
        st.push(root);

        while (!st.empty())
        {
            TreeNode *node = st.top();
            st.pop();
            ans.push_back(node->val);

            // Push right first so that left is processed first
            if (node->right)
                st.push(node->right);
            if (node->left)
                st.push(node->left);
        }

        return ans;
    }
};

int main()
{
    return 0;
}