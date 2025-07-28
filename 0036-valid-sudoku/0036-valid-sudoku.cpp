class Solution {
public:
    vector<vector<bool>> row{9, vector<bool>(10, false)};
    vector<vector<bool>> col{9, vector<bool>(10, false)};
    vector<vector<bool>> box{9, vector<bool>(10, false)};

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0 ; i<9 ; i++) {
            for(int j=0 ; j<9 ; j++) {
                if(board[i][j]=='.')
                    continue;
                int num = board[i][j] - '0';
                int boxIndex = (i/3)*3 + j/3;
                if(row[i][num] || col[j][num] || box[boxIndex][num]) {
                    return false;
                }
                row[i][num] = col[j][num] = box[boxIndex][num] = true;
            }
        }
        return true;
    }

};