class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        stack<TreeNode*> st;
        TreeNode* root = new TreeNode(preorder[0]);
        TreeNode* curr;
        st.push(root);
        for(int i=1 ; i<preorder.size() ; i++) {
            curr = NULL;
            while(!st.empty() && st.top()->val < preorder[i]) {
                curr = st.top();
                st.pop();
            }
            //greater elements and the right root is found
            if( curr ) {
                curr->right = new TreeNode(preorder[i]);
                st.push(curr->right);
            } else {
                curr = st.top();
                curr->left = new TreeNode(preorder[i]);
                st.push(curr->left);
            }
        }

        return root;
    }
};