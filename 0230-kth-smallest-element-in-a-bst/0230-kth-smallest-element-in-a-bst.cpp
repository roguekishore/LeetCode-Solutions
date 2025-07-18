/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<TreeNode*> arr;
        inOrder(root, arr);
        return arr[k-1]->val;

    }

    void inOrder(TreeNode* root, vector<TreeNode*>& arr) {
        if(root) {
            inOrder(root->left, arr);
            arr.push_back(root);
            inOrder(root->right, arr);
        }
    }
};