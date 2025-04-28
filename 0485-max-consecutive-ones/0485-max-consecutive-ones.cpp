class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int size = nums.size();
        int maxCount = 0;
        if(size == 1) {
            if(nums[0] == 1)
                return true;
            
            else
                return false;
        }
        int left = 0;
        int count = 0;
        for(int i = 0; i<size ; i++) {
            if(nums[i] == 1)
                count++;
            else {
                maxCount = max(maxCount, count);
                count = 0;
            }   
        }
        return max(count,maxCount);
    }
};