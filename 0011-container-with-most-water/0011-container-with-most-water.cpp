class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = INT_MIN;
        int left = 0;
        int right = height.size()-1;

        while(left<right) {
            int currArea = min(height[left], height[right]) * (right-left);
            maxArea = max(maxArea, currArea);

            if(height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea;
        // for(int i = 0 ; i<height.size()-1 ; i++) {
        //     for(int j = i+1 ; j<height.size() ; j++) {
        //         int x = abs((i+1) - (j+1));
        //         int y = min(height[i], height[j]);
        //         maxArea = max(maxArea, (x*y));
        //     }
        // }

        // map<int, int> map;
        // int maxHeight = 0;
        // int maxIndex = 0;

        // for(int i=0 ; i<height.size() ; i++) {
        //     if(height[i] > maxHeight) {
        //         maxHeight = height[i];
        //         maxIndex = i+1;
        //     }
        //     map[height[i]] = i+1;
        // }

        // for(auto it : map) {
        //     int x = abs(maxIndex - it.second);
        //     int y = it.first;
        //     maxArea = max(maxArea, (x*y));
        // }

        // return maxArea;

    }
};