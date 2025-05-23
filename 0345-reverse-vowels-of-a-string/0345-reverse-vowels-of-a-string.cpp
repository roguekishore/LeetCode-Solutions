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
            if(isVowel(s[left]) && isVowel(s[right]) && (left<=right)) {
                swap(s[left] , s[right]);
            }
            else if(isVowel(s[left]) && !isVowel(s[right])) {
                while(right > left) {
                    right--;
                    if(isVowel(s[right])) {
                        swap(s[left], s[right]);
                        break;
                    }
                }
            } else if(!isVowel(s[left]) && isVowel(s[right])) {
                while(right > left) {
                    left++;
                    if(isVowel(s[left])) {
                        swap(s[left], s[right]);
                        break;
                    }
                }
            }
            left++;
            right--;
        }
        return s;
    }
};