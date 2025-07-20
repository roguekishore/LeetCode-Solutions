class Solution {
  public:
    int isSumProperty(Node *root) {
        bool check = checkSumProperty(root);
        return (check) ? 1 : 0;
    }
    
    bool checkSumProperty(Node* root) {
        if(!root)
            return true;
        
        if(!root->left && !root->right)
            return true;
            
        int a = (root->left) ? root->left->data : 0;
        int b = (root->right) ? root->right->data : 0;
        
        return (root->data == (a+b)) && checkSumProperty(root->left) && checkSumProperty(root->right);
    }
};