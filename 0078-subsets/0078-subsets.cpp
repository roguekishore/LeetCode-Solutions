class Solution {
public:
    vector<vector<int>> result;
    vector<int> temp;
    void findCombinations(int start, int n, vector<int>& nums) {
        if(start == n) {
            return;
        }

        for(int i=start ; i<n ; i++) {
            temp.push_back(nums[i]);
            result.push_back(temp);
            findCombinations(i+1, n, nums);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        result.push_back({});
        findCombinations(0, nums.size(), nums);
        return result;
    }
};