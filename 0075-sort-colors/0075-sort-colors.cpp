class Solution {
public:
    void sortColors(vector<int>& nums) {
        int size = nums.size();
        for(int i=0 ; i<size-1 ; i++) {
            for(int j=i+1 ; j<size ; j++) {
                if( nums[i]>nums[j] ){
                    swap(nums[i],nums[j]);
                }
            }
        }
    }
};