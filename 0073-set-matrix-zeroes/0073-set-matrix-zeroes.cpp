class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        if(matrix.empty())
            return;
        int rowSize = matrix.size();
        if(matrix[0].empty())
            return;
        int colSize = matrix[0].size();
    
        set<int> cols;
        set<int> rows;

        for(int i=0 ; i<rowSize ; i++) {
            for(int j=0 ; j<colSize ; j++) {
                if(matrix[i][j] == 0) {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }

        for(int row : rows) {
            for(int j=0 ; j<colSize ; j++) {
                matrix[row][j] = 0;
            }
        } 

        for(int col : cols) {
            for(int j=0 ; j<rowSize ; j++) {
                matrix[j][col] = 0;
            }
        }
    }
};