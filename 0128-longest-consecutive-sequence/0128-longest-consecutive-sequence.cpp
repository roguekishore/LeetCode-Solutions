class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int size = nums.size();
        if(nums.size()==0) {
            return 0;
        }
        sort(nums.begin(), nums.end());

        int maxCount = 1;
        int count = 1;

        for(int i=1 ; i<size ; i++) {
            if(nums[i] == nums[i-1]) {
                continue;
            }
            else if(nums[i]-1 == nums[i-1]) {
                count++;
            }
            else {
                maxCount = max(count,maxCount);
                count = 1;
            }
        }

        return max(maxCount,count);
    }
};