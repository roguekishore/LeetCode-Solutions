class Solution {
public:
    bool isAnagram(string s, string t) {
        // int size = s.size();
        // if(size != t.size())
        //     return false;

        // bool isAnagram = true;
        // map<char, int> map1;
        // for(int i=0 ; i<size ; i++) {
        //     map1[s[i]]++;
        // }

        // for(int i=0 ; i<size ; i++) {
        //     if(map1.find(t[i]) == map1.end() || map1[t[i]] == 0) {
        //         return false;
        //     }
        //     map1[t[i]]--;
        // }

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s==t;

        //return isAnagram;
    }
};