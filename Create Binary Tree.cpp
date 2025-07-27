#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    // Attributes are declared as below
    int data;
    Node *left;
    Node *right;

    // Parameterised Constructor
    Node(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};
// BinaryTree Function
Node *BinaryTree()
{
    int x;
    cin >> x;
    if (x == -1)
        return nullptr;
    Node *temp = new Node(x);
    cout << "Enter the Left child of " << x << endl;
    temp->left = BinaryTree();
    cout << "Enter the Right child of " << x << endl;
    temp->right = BinaryTree();
    return temp;
}
int main()
{
    cout << "Enter the root Node : " << endl;
    Node *root = BinaryTree();
    return 0;
}
