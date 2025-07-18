class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) {
            return NULL;
        }
        if(key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val){
            root->right = deleteNode(root->right, key);
        } else {
            root = helper(root);
        }
        return root;
    }

    TreeNode* helper(TreeNode* node) {
        if(!node->left) {
            return node->right;
        }

        if(!node->right) {
            return node->left;
        }

        TreeNode* rightChild = node->right; 
        TreeNode* leftChild = node->left;
        TreeNode* rightMost = findRightMost(leftChild);

        rightMost->right = rightChild;
        delete node;
        return leftChild;
    }

    TreeNode* findRightMost(TreeNode* node) {
        if(!node->right) 
            return node;
        return findRightMost(node->right);
    }
};