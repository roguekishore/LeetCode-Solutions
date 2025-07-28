class Solution {
public:
    vector<string> res;
    string temp = "";

    void genCombinations(int idx, string& digits, map<char, string>& letters) {
        if(temp.size() == digits.size()) {
            res.push_back(temp);
            return;
        }
        if(idx == digits.size()) {
            return;
        }
        for(char c:letters[digits[idx]]) {
            temp.push_back(c);
            genCombinations(idx+1, digits, letters);
            temp.pop_back();
        }
    } 

    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) {
            return {};
        }
        map<char, string> letters;
        letters['2'] = "abc";
        letters['3'] = "def";
        letters['4'] = "ghi";
        letters['5'] = "jkl";
        letters['6'] = "mno";
        letters['7'] = "pqrs";
        letters['8'] = "tuv";
        letters['9'] = "wxyz";
        genCombinations(0,digits,letters);
        return res;
    }
};