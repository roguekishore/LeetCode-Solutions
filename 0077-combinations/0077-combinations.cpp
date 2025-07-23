class Solution {
public:
    vector<vector<int>> result;
    vector<int> temp;

    void genCombinations(int idx, int k, int n, vector<int>& arr) {
        if(temp.size() == k) {
            result.push_back(temp);
            return;
        }

        if(idx >= n) {
            return;
        }

        temp.push_back(arr[idx]);
        genCombinations(idx+1, k, n, arr);
        temp.pop_back();
        genCombinations(idx+1, k, n, arr);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> arr(n);
        for(int i=0 ; i<n ; i++) {
            arr[i] = i+1;
        }

        genCombinations(0,k,arr.size(),arr);
        return result;
    }
};