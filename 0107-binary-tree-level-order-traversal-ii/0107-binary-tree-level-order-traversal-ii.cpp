class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root)
            return {};
        
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int n = q.size();
            vector<int> arr;
            for(int i=0 ; i<n ; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left) {
                    q.push(curr->left);
                }
                if(curr->right) {
                    q.push(curr->right);
                }
                arr.push_back(curr->val);
            }
            res.push_back(arr);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};