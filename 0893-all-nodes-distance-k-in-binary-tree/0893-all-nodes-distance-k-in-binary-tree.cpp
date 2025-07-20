class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // if(!root->left && !root->right) {
        //     if(k==1) {
        //         return {root->val};
        //     } else {
        //         return {};
        //     }
        // }
        unordered_map<TreeNode*, TreeNode*> childtoparent;
        queue<TreeNode*> q;

        q.push(root);
        childtoparent[root] = NULL;

        while(!q.empty()) {
            int n = q.size();
            for(int i=0 ; i<n ; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left) {
                    childtoparent[curr->left] = curr;
                    q.push(curr->left);
                }
                if(curr->right) {
                    childtoparent[curr->right] = curr;
                    q.push(curr->right);
                }
            }
        }

        unordered_map<TreeNode*, bool> visited;
        q.push(target);

        while(k-- > 0) {
            int n = q.size();
            for(int i=0 ; i<n ; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left && !visited[curr->left]) {
                    q.push(curr->left);
                }
                if(curr->right && !visited[curr->right]) {
                    q.push(curr->right);
                }
                if(childtoparent[curr] && !visited[childtoparent[curr]]) {
                    q.push(childtoparent[curr]);
                }
                visited[curr] = true;
            }
        }
        vector<int> arr;

        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            arr.push_back(curr->val);
        }

        return arr;
    }
};