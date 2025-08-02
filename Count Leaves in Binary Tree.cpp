/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
#define val data

// Class Solution
class Solution {
  public:
    // Function to count the number of leaf nodes in a binary tree.
    int countLeaves(Node* root) {
        // write code here
        queue<Node*> q;
        if (!root)
            return false;
        q.push(root);
        int count=0;
        while (!q.empty()) {
            Node* node = q.front();
            q.pop();
            if (!(node->left) && !(node->right)) {
                count++;
            }
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        return count;
    }
};
