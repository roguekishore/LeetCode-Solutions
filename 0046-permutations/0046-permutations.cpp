class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        vector<bool> visited(nums.size(), false);
        permutation(nums,nums.size(),temp,visited,res);
        return res;
    }

    void permutation(vector<int>& nums, int n, vector<int>& temp, vector<bool>& visited, vector<vector<int>>& res){
        if(temp.size() == n) {
            res.push_back(temp);
            return;
        }

        for(int i=0 ; i<n ; i++) {
            if(!visited[i]) {
                visited[i] = true;
                temp.push_back(nums[i]);
                permutation(nums,n,temp,visited,res);
                temp.pop_back();
                visited[i] = false;
            }
        }
    }
};