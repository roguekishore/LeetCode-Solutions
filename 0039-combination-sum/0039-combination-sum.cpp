class Solution {
public:
    vector<vector<int>> result;
    vector<int> temp;
    void findCombinations(int start, int n, int target, vector<int>& candidates) {
        if(target == 0) {
            result.push_back(temp);
            return;
        }
        if(target<0) {
            return;
        }

        for(int i=start ; i<n ; i++) {
            temp.push_back(candidates[i]);
            findCombinations(i, n, target-candidates[i], candidates);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        findCombinations(0,candidates.size(),target,candidates);
        return result;
    }
};