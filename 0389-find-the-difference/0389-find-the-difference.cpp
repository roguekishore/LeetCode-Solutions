class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char, int> map;
        for(int i=0 ; i<s.size() ; i++) {
            map[s[i]]++;
        }
        for(int i=0 ; i<t.size() ; i++) {
            map[t[i]]--;
        }

        auto it = map.rbegin();
        cout<<it->first<<" "<<it->second;
        for(const auto it : map) {
            if(it.second == -1) {
                return it.first;
            }
        }

        return '0';
    }
};