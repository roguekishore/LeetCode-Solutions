class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root) {
            return true;
        }
        cout<<checkHeight(root);
        return checkBalanced(root);
    }

    bool checkBalanced(TreeNode* root) {
        if(!root) 
            return true;
        if(!root->left && !root->right)
            return true;
            
        int left = checkHeight(root->left);
        int right = checkHeight(root->right);

        return (abs(left-right)<=1) && checkBalanced(root->left) && checkBalanced(root->right);
    }

    int checkHeight(TreeNode* root) {
        if(!root)
            return 0;
        
        return 1 + max(checkHeight(root->left), checkHeight(root->right));
    }
};