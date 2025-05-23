class Solution {
public:
    bool isVowel(char ch) {
        string s = "AEIOUaeiou";
        for(int i=0 ; i<s.size() ; i++) {
            if(s[i] == ch) {
                return true;
            }
        }

        return false;
    }
    string reverseVowels(string s) {
        int left = 0;
        int right = s.size()-1;

        while(left<=right) {
            while(left<right && !isVowel(s[right])) {
                right--;
            }
            while(left<right && !isVowel(s[left])) {
                left++;
            }
            swap(s[left],s[right]);
            left++;
            right--;
        }
        return s;
    }
};