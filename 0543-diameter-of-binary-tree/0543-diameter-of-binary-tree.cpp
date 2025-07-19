class Solution {
public:
    int res = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        helper(root);
        return res;
    }

    int helper(TreeNode* root) {
        if(!root) 
            return 0;

        int left = helper(root->left);
        int right = helper(root->right);
        res = max(res, left+right);
        return 1 + max(left,right); //distance to travel to that node(1)
    }
};