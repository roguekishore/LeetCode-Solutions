class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        if(groups.size() == 1) {
            return words;
        }

        vector<string> res = {words[0]};
        for(int i=1 ; i<groups.size() ; i++) {
            if(groups[i] != groups[i-1]) {
                res.push_back(words[i]);
            }
        }

        return res;
    }
};