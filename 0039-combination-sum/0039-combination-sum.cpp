class Solution {
public:
    vector<vector<int>> result;
    vector<int> temp;
    void findCombinations(int idx, int n, int target, vector<int>& candidates) {
        if(target == 0) {
            result.push_back(temp);
            return;
        }
        if(target<0 || idx==n) {
            return;
        }

        temp.push_back(candidates[idx]);
        findCombinations(idx,n,target-candidates[idx],candidates);
        temp.pop_back();
        findCombinations(idx+1,n,target,candidates);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        findCombinations(0,candidates.size(),target,candidates);
        return result;
    }
};