class Solution {
     
  public:
    int count;
    void Measure(Node * root){
        if(root==nullptr)return;
        count++;
        Measure(root->left);
        Measure(root->right);
        return;
    }
    int getSize(Node* node) {
        // code here
        count=0;
        Measure(node);
        return count;
    }
};

//Recursive Method :2 

class Solution {
     
  public:
    int count=0;

    int getSize(Node* root) {
        // code here
        if(root==nullptr)return 0;
        int left=diameterOfBinaryTree(root->left);
        int right=diameterOfBinaryTree(root->right);
        return 1+left+right;

    }
};
