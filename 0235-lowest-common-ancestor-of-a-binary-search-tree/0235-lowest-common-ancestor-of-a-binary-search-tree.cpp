class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* x = (p->val<q->val) ? p : q;
        TreeNode* y = (p->val>q->val) ? p : q;
        return findCommonAncestor(root,x,y);
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