class Solution {
public:
    string romanNumerals(int num, int place, map<int, char> numerals) {
        string result;

        if (num == 0) {
            return "";
        } else if (num == 4 || num == 9) {
            result += (numerals[place]);
            result += numerals[(num+1) * place];
        } else if (num <= 3) {
            for( int i = 0 ; i<num ; i++)
                result += (numerals[place]);
        }
        else if (num >= 5 && num<=8) {
            result += (numerals[5*place]);
            for(int i=0 ; i<num-5 ; i++) {
                result+= (numerals[place]);
            }
        }
        return result;
    }
    string intToRoman(int num) {
        map<int, char> numerals;
        numerals[1] = 'I';
        numerals[5] = 'V';
        numerals[10] = 'X';
        numerals[50] = 'L';
        numerals[100] = 'C';
        numerals[500] = 'D';
        numerals[1000] = 'M';

        string result = "";
        int place = 1;
        while(num > 0) {
            int l = num%10;
            result = romanNumerals(l, place, numerals) + result;
            num /= 10;
            place *= 10;
        }
        return result;
    }
};