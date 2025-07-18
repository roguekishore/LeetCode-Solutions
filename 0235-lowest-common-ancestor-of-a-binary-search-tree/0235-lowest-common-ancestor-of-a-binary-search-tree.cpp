class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return findCommonAncestor(root,p,q);
    }

    TreeNode* findCommonAncestor(TreeNode* root, TreeNode* x, TreeNode* y) {
        if(x->val < root->val && y->val < root->val) {
            return findCommonAncestor(root->left, x, y);
        }
        else if(x->val > root->val && y->val > root->val) {
            return findCommonAncestor(root->right, x, y);
        }
        else {
            return root;
        }
    }
};