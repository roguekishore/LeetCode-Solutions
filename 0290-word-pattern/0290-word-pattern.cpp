class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char, string> ctos;
        map<string, char> stoc;
        vector<string> arr;
        int i=0;
        int t=0;
        while(i<s.size()) {
            string st = "";
            while(i<s.size() && s[i]!=' ') {
                st += s[i];
                i++;
            }
            arr.push_back(st);
            i++;

            char ch = pattern[t++];
            if(ctos.find(ch) == ctos.end()) {
                if(stoc.find(st) == stoc.end()) {
                    ctos[ch] = st;
                    stoc[st] = ch;
                } else {
                    return false;
                }
            } else {
                if(ctos[ch] == st) {
                    continue;
                } else {
                    return false;
                }
            }
        }

        if(t != pattern.size()) {
            return false;
        }

        for(int i=0 ; i<arr.size() ; i++) {
            cout<<arr[i]<<endl;
        } 
        return true;
    }
};