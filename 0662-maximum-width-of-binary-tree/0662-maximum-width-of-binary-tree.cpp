class Solution {
public:
    
    long long maxWidth = 0;
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) {
            return 0;
        }

        queue<pair<TreeNode*,long long>> q;
        q.push({root,1});
        while(!q.empty()) {
            long long n = q.size();
            long long start = q.front().second;
            long long end = q.back().second;
            maxWidth = max(maxWidth, end-start+1);

            for(int i=0 ; i<n ; i++) {
                TreeNode* curr = q.front().first;
                long long index = q.front().second - start;
                q.pop();

                if(curr->left) {
                    q.push({curr->left, (long long)2*index});
                }
                if(curr->right) {
                    q.push({curr->right, (long long)2*index+1});
                }
            }

        }
        return maxWidth;
    }
};