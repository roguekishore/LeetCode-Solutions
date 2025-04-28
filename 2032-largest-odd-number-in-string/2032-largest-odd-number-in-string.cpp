class Solution {
public:
    string largestOddNumber(string num) {
        while (num.size() > 0) {
            char ch = num[num.size()-1];
            if( (ch - '0') % 2 == 1) {
                return num;
            }

            else {
                num.pop_back();
            }
        }

        return num;
    }
};