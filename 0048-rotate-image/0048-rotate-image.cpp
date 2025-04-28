class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        for(int i=0 ; i<rows ; i++) {
            for(int j=0 ; j<=i ; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        int times = cols/2;
        for(int i=0 ; i<rows ; i++) {
            int colstart = 0;
            int colend = cols - 1;
            for(int j=0 ; j<times ; j++) {
                swap(matrix[i][colstart], matrix[i][colend]);
                colstart++;
                colend--;
            }
        }
    }
};