class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) {
            return s;
        }
        string res = "";
        bool down = true;
        bool zigzag = false;
        vector<vector<char>> matrix(numRows, vector<char>(1000, '0'));

        int rows = numRows;
        int cols = numRows;
        int trow = 0;
        int tcol = 0;

        int i = 0;
        while(i<s.size()) {
            while(trow<rows && down && i<s.size()) {
                matrix[trow++][tcol] = s[i++];
                
                if(trow == rows) {
                    trow--;
                    down = false;
                    zigzag = true;
                    i--;
                }
            }

            while(tcol>=0 && zigzag && i<s.size()) {
                matrix[trow--][tcol++] = s[i++];
                
                if(trow == -1) {
                    tcol--;
                    trow = 0;
                    down = true;
                    zigzag = false;
                    i--;
                }
            }
        }

        for(int i=0 ; i<matrix.size() ; i++) {
            for(int j=0 ; j<matrix[i].size() ; j++) {
                if(matrix[i][j] != '0') {
                    res += matrix[i][j];
                }
            }
        }
        return res;
    }
};