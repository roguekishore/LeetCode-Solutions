class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> childtoparent;
        queue<TreeNode*> q;
        q.push(root);
        childtoparent[root] = NULL;
        TreeNode* target = NULL;
        int k = 0;

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

                if(curr->val == start) {
                    target = curr;
                }
            }
        }

        unordered_map<TreeNode*, bool> visited;
        q.push(target);

        while(!q.empty()) {
            int n = q.size();
            k++;
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

        return k-1;
    }
};