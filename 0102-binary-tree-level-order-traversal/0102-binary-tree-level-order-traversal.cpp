class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) {
            return {};
        }
        vector<vector<int>> arr;
        queue<TreeNode*> q;
        vector<int> temp;
        q.push(root);
        temp.push_back(root->val);
        arr.push_back(temp);
        temp.clear();
        TreeNode* curr;
        while(!q.empty()) {
            int n = q.size();
            while(n--) {
            curr = q.front();
            q.pop();
            if(curr->left) {
                temp.push_back(curr->left->val);
                q.push(curr->left);
            }
            if(curr->right) {
                temp.push_back(curr->right->val);
                q.push(curr->right);
            }
            }
            if(!temp.empty())
                arr.push_back(temp);
            temp.clear();
        }
        return arr;
    }
};