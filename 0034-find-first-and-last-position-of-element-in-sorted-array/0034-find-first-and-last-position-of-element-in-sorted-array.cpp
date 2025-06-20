class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = -1, end = -1;
        int size = nums.size();

        for(int i=0 ; i<size ; i++) {
            if(nums[i]==target) {
                start = i;
                break;
            }
        }

        for(int i=size-1 ; i>=0 ; i--) {
            if(nums[i]==target) {
                end = i;
                break;
            }
        }

        return {start,end};
    }
};