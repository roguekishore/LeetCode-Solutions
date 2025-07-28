class Solution {
public:
    int solutions = 0;

    bool isSafe(int x, int y, int n, vector<vector<int>>& board) {
        for(int i=0 ; i<n ; i++) {
            if(board[x][i] == 1)
                return false;
        }
        for(int i=x, j=y ; i>=0 && j>=0 ; i--, j--) {
            if(board[i][j] == 1)
                return false;
        }
        for(int i=x, j=y ; i<n && j>=0 ; i++, j--) {
            if(board[i][j] == 1)
                return false;
        }
        return true;
    }

    void nQueens(int x, int y, int n, vector<vector<int>>& board) {
        if( y==n ) {
            solutions++;
            return;
        }

        for(int i=0 ; i<n ; i++) {
            if(isSafe(i,y,n,board)) {
                board[i][y] = 1;
                nQueens(0,y+1,n,board);
                board[i][y] = 0;
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<int>> board(n, vector<int>(n, 0));
        nQueens(0,0,n,board);
        return solutions;
    }
};