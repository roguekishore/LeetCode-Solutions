class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        
        return helper(root);
    }

    int helper(TreeNode* root) {
        if(!root) 
            return 0;

        int left = height(root->left);
        int right = height(root->right);

        return max({left+right, helper(root->left), helper(root->right)});
    }

    int height(TreeNode* root) {
        if(!root) {
            return 0;
        }

        return 1+max(height(root->left),height(root->right));
    }
};