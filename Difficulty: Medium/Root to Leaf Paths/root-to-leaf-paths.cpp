class Solution {
  public:
    vector<int> curr;
    vector<vector<int>> res;
    
    vector<vector<int>> Paths(Node* root) {
        if(!root) {
            return {};
        }
        sol(root);
        return res;
    }
    
    void sol(Node* root) {
        if(!root) {
            return;
        }
        if(!root->left && !root->right) {
            curr.push_back(root->data);
            res.push_back(curr);
            curr.pop_back();
            return;
        }
        curr.push_back(root->data);
        sol(root->left);
        sol(root->right);
        curr.pop_back();
    }
};