class Solution {
public:
    int maxDifference(string s) {
        int oddmax = 0;
        int evenmax = INT_MAX;

        map<char, int> map;
        for(char c:s) {
            map[c]++;
        }

        for(auto it : map) {
            if(it.second%2==0) {
                evenmax = min(evenmax, it.second);
            } else {
                oddmax = max(oddmax, it.second);
            }
        }

        return oddmax - evenmax;
    }
};