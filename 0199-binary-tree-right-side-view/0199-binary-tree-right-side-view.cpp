class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};

        queue<TreeNode*> q;
        q.push(root);
        vector<int> res;

        while(!q.empty()) {
            int n = q.size();
            vector<int> arr;

            for(int i=0 ; i<n ; i++) {
                TreeNode* curr = q.front();
                q.pop();

                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);

                arr.push_back(curr->val);
                cout<<curr->val<<" ";
            }
            cout<<endl;
            res.push_back(arr[n-1]);
        }
        return res;
    }
};