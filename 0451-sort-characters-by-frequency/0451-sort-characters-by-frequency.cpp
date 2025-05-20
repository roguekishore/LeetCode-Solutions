class Solution {
public:

    string frequencySort(string s) {
        unordered_map<char, int> mp;
        multimap<int, char> mm;

        for(int i=0 ; i<s.size() ; i++) {
            mp[s[i]]++;
        }

        for(auto a : mp) {
            mm.insert({a.second, a.first});
        }

        string res = "";
        for(auto it = mm.rbegin() ; it!=mm.rend() ; ++it) {
            res += string(it->first, it->second);
        }
        return res;
    }
};