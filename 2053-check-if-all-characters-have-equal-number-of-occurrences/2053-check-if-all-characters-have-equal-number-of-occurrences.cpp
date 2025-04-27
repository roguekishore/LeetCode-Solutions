class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int size = s.size();
        unordered_map<char, int> mpp;
        for(int i=0 ; i<size ; i++) {
            mpp[s[i]]++;
        }

        auto it = mpp.begin();
        int value = it->second;
        for( auto it : mpp ) {
            if( it.second == value) {
                continue;
            }
            else {
                return false;
            }
        }    
        //return true
        return true;
            
    }
};