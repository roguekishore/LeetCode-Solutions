class Solution {
public:
    vector<vector<bool>> rowUsed{9, vector<bool>(10, false)};
    vector<vector<bool>> colUsed{9, vector<bool>(10, false)};
    vector<vector<bool>> boxUsed{9, vector<bool>(10, false)};

    int getBoxIndex(int r, int c) {
        return (r/3)*3+(c/3);
    }

    bool isSafe(int num, int x, int y) {
        if(!rowUsed[x][num] && !colUsed[y][num] && !boxUsed[getBoxIndex(x,y)][num])
            return true;
        return false;
    }

    bool solve(int x, int y, vector<vector<char>>& board) {
        if(x == 9)
            return true;
        if(y == 9)
            return solve(x+1,0,board);
        
        if(board[x][y] != '.') {
            return solve(x,y+1,board);
        }

        for(int i=1 ; i<=9 ; i++) {
            if(isSafe(i,x,y)) {
                board[x][y] = i + '0';
                rowUsed[x][i] = colUsed[y][i] = boxUsed[getBoxIndex(x,y)][i] = true;
                if(solve(x,y+1,board)) {
                    return true;
                }
                board[x][y] = '.';
                rowUsed[x][i] = colUsed[y][i] = boxUsed[getBoxIndex(x,y)][i] = false;
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        for(int i=0 ; i<9 ; i++) {
            for(int j=0 ; j<9 ; j++) {
                if(board[i][j] == '.')
                    continue;
                int num = board[i][j] - '0';
                rowUsed[i][num] = true;
                colUsed[j][num] = true;
                boxUsed[getBoxIndex(i,j)][num] = true;
            }
        }
        solve(0,0,board);
    }
};