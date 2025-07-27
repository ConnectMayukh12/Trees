#include <bits/stdc++.h>
using namespace std;
#define int long long

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
    void PostOrder(TreeNode *root)
    {
        if (root == nullptr)
            return;
        PostOrder(root->left);
        PostOrder(root->right);
        ans.push_back(root->val);
        return;
    }
    vector<int> postorderTraversal(TreeNode *root)
    {
        PostOrder(root);
        return ans;
    }
};
// Iterative Approach
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        stack<TreeNode *> st;
        TreeNode *current = root;
        TreeNode *lastVisited = nullptr;

        while (current || !st.empty())
        {
            if (current)
            {
                st.push(current);
                current = current->left;
            }
            else
            {
                TreeNode *node = st.top();
                // if right child exists and hasn't been visited
                if (node->right && lastVisited != node->right)
                {
                    current = node->right;
                }
                else
                {
                    ans.push_back(node->val);
                    lastVisited = node;
                    st.pop();
                }
            }
        }

        return ans;
    }
};

// Iterative  Optimised Approach
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
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

            // Push left first so right is processed before left
            if (node->left)
                st.push(node->left);
            if (node->right)
                st.push(node->right);
        }

        reverse(ans.begin(), ans.end()); // Reverse to get Left → Right → Root
        return ans;
    }
};
int32_t main()
{

    cout << "Hello World" << endl;
    return 0;
}