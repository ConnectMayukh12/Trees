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
