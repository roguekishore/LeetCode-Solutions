class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> dp(row, vector<int>(col, 0));

        int maxA = 0;
        for(int i=0 ; i<row ; i++) {
            dp[i][0] = matrix[i][0] - '0';
            maxA = max(maxA, dp[i][0]);
        }
        for(int i=0 ; i<col ; i++) {
            dp[0][i] = matrix[0][i] - '0';
            maxA = max(maxA, dp[0][i]);
        }
        for(int i=1 ; i<row ; i++) {
            for(int j=1 ; j<col ; j++) {
                if(matrix[i][j] == '1') {
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                    maxA = max(maxA, dp[i][j]);
                }
            }
        }
        for(int i=0 ; i<row ; i++) {
            for(int j=0 ; j<col ; j++) {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return maxA*maxA;
    }
};