class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};

        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        bool ltr = true;
        while(!q.empty()) {
            int n = q.size();
            vector<int> arr(n);

            for(int i=0 ; i<n ; i++) {
                TreeNode* curr = q.front();
                q.pop();
                int index = ltr ? i : n-i-1;
                if(curr->left) {
                    q.push(curr->left);
                }
                if(curr->right) {
                    q.push(curr->right);
                }
                arr[index] = (curr->val);
            }
            ltr = !ltr;
            res.push_back(arr);
        }
        return res;
    }
};