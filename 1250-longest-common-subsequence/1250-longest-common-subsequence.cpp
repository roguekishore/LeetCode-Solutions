class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int rows = text1.size();
        int cols = text2.size();
        vector<vector<int>> dp(rows+1, vector<int>(cols+1, 0));
        
        for(int i=1 ; i<=rows ; i++) {
            for(int j=1 ; j<=cols ; j++) {
                if(text1[i-1] == text2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        // for(int i=0 ; i<=rows ; i++) {
        //     for(int j=0 ; j<=cols ; j++) {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        return dp[rows][cols];
    }
};