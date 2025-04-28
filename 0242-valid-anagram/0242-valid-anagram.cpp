class Solution {
public:
    bool isAnagram(string s, string t) {
        int size = s.size();
        if(size != t.size())
            return false;

        bool isAnagram = true;
        map<char, int> map1;
        map<char, int> map2;
        for(int i=0 ; i<size ; i++) {
            map1[s[i]]++;
            map2[t[i]]++;
        }

        for(int i=0 ; i<size ; i++) {
            if(map1[s[i]] != map2[s[i]])
                return false;
        }

        return isAnagram;
    }
};