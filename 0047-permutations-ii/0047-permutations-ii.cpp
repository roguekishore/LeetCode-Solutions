class Solution {
public:
    set<vector<int>> res;
    vector<vector<int>> result;
    vector<int> temp;

    void genPermutations(vector<int>& nums, int n, vector<bool>& visited) {
        if(temp.size() == nums.size()) {
            res.insert(temp);
            return;
        }

        for(int i=0 ; i<n ; i++) {
            if(!visited[i]) {
                temp.push_back(nums[i]);
                visited[i] = true;
                genPermutations(nums,n,visited);
                visited[i] = false;
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> visited(nums.size(), false);
        genPermutations(nums, nums.size(), visited);
        for(vector<int> a : res) {
            result.push_back(a);
        }
        return result;
    }
};