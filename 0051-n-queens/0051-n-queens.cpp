class Solution {
public:
    vector<vector<string>> result;
    bool isSafe(int row, int col, int n, vector<string> board) {
        for(int i=0 ; i<row ; i++) {
            if(board[i][col] == 'Q') {
                return false;
            }
        }
        for(int i=row, j=col ; i>=0 && j>=0 ; i--, j--) {
            if(board[i][j] == 'Q') {
                return false;
            }
        }
        for(int i=row, j=col; i>=0 && j<n ; i--, j++) {
            if(board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
    
    void nQueens(int row, int n, vector<string> board) {
        if( row == n ) {
            result.push_back(board);
            return;
        }
        for(int col = 0 ; col<n ; col++) {
            if(isSafe(row,col,n,board)) {
                board[row][col] = 'Q';
                nQueens(row+1,n,board);
                board[row][col] = '.'; 
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        
        vector<string> board(n, string(n,'.'));
        nQueens(0,n,board);
        return result;
    }
};