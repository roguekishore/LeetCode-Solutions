class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> mpp;
        vector<bool> arr(256, false);
        int size = s.size();
        for (int i = 0; i < size; i++) {
            if (arr[t[i] - 0] == false) {
                arr[t[i] - 0] = true;
                if (mpp[s[i]] == NULL) {
                    mpp[s[i]] = t[i];
                } else if (mpp[s[i]] == t[i]) {
                    continue;
                } else {
                    return false;
                }
            }

            else {
                if(mpp[s[i]] == t[i])
                    continue;

                else
                    return false;
            }
        }
        for (auto it : mpp) {
            cout << it.first << "->" << it.second << endl;
        }

        return true;
    }
};