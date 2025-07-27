#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left, *right;

    Node(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};
void showBinaryTree(Node *root)
{
    if (root == nullptr)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        cout << temp->data << ": ";
        if (temp->left)
        {
            cout << "L->" << temp->left->data << " ";
            q.push(temp->left);
        }
        else
            cout << "L->NULL ";
        if (temp->right)
        {
            cout << "R->" << temp->right->data << " ";
            q.push(temp->right);
        }
        else
            cout << "R->NULL ";
        cout << endl;
    }
}
int main()
{
    queue<Node *> q;
    int root_value;
    cout << "Enter the root Node: " << endl;
    cin >> root_value;
    Node *root = new Node(root_value);
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        int left, right;
        cout << "Enter the Left Node :" << endl;
        cin >> left;

        if (left != -1)
        {
            Node *left_node = new Node(left);
            temp->left = left_node;
            q.push(left_node);
        }
        cout << "Enter the Right Node :" << endl;
        cin >> right;
        if (right != -1)
        {
            Node *right_node = new Node(right);
            temp->right = right_node;
            q.push(right_node);
        }
    }

    showBinaryTree(root);

    return 0;
}
