class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int rows = image.size();
        int cols = image[0].size();
        

        vector<vector<int>> result(rows);

        for(int i=0 ; i<rows ; i++) {
            int start = 0;
            int end = cols - 1;
            for(int j=0 ; j< cols / 2 ; j++) {
                swap(image[i][start++], image[i][end--]);
            }
        }

        for(int i=0 ; i<rows ; i++) {
            for(int j=0 ; j<cols ; j++) {
                image[i][j] = image[i][j] ^ 1;
            }
        }

        return image;
    }
};