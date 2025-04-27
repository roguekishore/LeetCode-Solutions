class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int size = nums.size();

        int minWindow = size+1;
        int left = 0;
        int tempSum = 0;
        
        for(int right=0 ; right<size ; right++) {
            tempSum += nums[right];

            while(tempSum >= target) {
                minWindow = min(minWindow, right-left+1);
                tempSum -= nums[left];
                left++;
            }


        } 

        return (minWindow==size+1) ? 0 : minWindow;
    }
};