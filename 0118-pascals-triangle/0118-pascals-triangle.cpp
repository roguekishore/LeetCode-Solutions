class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // int arr[numRows][numRows];
        // for(int i=0 ; i<numRows ; i++){
        //     for(int j=0 ; j<numRows ; j++){
        //         arr[i][j] = 0;
        //     }
        // }

        // for(int i=0 ; i<numRows ; i++){
        //     for(int j=0 ; j<=i ; j++){
        //         if( j==0 ){
        //             arr[i][j] = 1;
        //             continue;
        //         }

        //         arr[i][j] = arr[i-1][j-1] + arr[i-1][j];

        //     }
        // }
        
        // vector<vector<int>> arra(numRows,vector<int>(numRows));
        // for(int i=0 ; i<numRows ; i++){
        //     for(int j=0 ; j<numRows ; j++){
        //         arra[i][j] = arr[i][j];
        //     }
        // }
        // return arra;

        vector<vector<int>> arr(numRows);

        for(int i=0 ; i<numRows ; i++){
            arr[i].resize(i+1);
            arr[i][0] = arr[i][i] = 1;

            for(int j=1 ; j<i ; j++){
                arr[i][j] = arr[i-1][j] + arr[i-1][j-1];
            }
        }

        return arr;
        
    }
};