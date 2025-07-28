class Solution {
public:
    bool solve(int x, int y, vector<vector<char>>& board) {
        if(y==9)
            return solve(x+1,0,board);
        if(x==9)
            return true;
        if(board[x][y] == '.')
            return solve(x,y+1,board);

        vector<bool> row(9, false);
        vector<bool> col(9, false);
        vector<bool> box(9, false);

        for(int i=0 ; i<9 ; i++) {
            if(board[x][i] == '.') continue;
            int num = board[x][i] - '0';
            if(row[num])
                return false;
            row[num] = true;
        }

        for(int i=0 ; i<9 ; i++) {
            if(board[i][y] == '.') continue;
            int num = board[i][y] - '0';
            if(col[num])
                return false;
            col[num] = true;
        }

        int dr = (x/3)*3;
        int dc = (y/3)*3;
        for(int i=dr ; i<dr+3 ; i++) {
            for(int j=dc ; j<dc+3 ; j++) {
                if(board[i][j] == '.') continue;
                int num = board[i][j] - '0';
                if(box[num])
                    return false;
                box[num] = true;
            }
        }
        
        if(solve(x,y+1,board))
            return true;

        return false;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        return solve(0,0,board);
    }
};