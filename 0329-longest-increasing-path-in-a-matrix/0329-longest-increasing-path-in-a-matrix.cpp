class Solution {
public:
    int rows, cols;
    int maxLen = 0;
    vector<pair<int,int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
    bool isValid(int x, int y, int nx, int ny, vector<vector<int>>& matrix) {
        if(nx<0 || nx>=rows || ny<0 || ny>=cols) {
            return false;
        }
        if(matrix[x][y] < matrix[nx][ny]) {
            return true;
        } else {
            return false;
        }
    }

    int solve(int x, int y, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if(dp[x][y] != -1) {
            return dp[x][y];
        }
        int maxL = 1;
        for(pair<int, int> d : dir) {
            int nx = x + d.first;
            int ny = y + d.second;

            if(isValid(x,y,nx,ny,matrix)) {
                maxL = max(maxL, 1+solve(nx,ny,matrix,dp));
            }
        }
        dp[x][y] = maxL;
        return maxL;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        rows = matrix.size();
        cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, -1));
        for(int i=0 ; i<rows ; i++) {
            for(int j=0 ; j<cols ; j++) {
                maxLen = max(maxLen, solve(i,j,matrix,dp));
            }
        }
        return maxLen;
    }
};