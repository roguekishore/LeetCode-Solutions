class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxd = -1;
        int n = nums.size();
        for(int i=0 ; i<n-1 ; i++) {
            for(int j=i+1 ; j<n ; j++) {
                if(nums[i] < nums[j]) {
                    maxd = max(maxd, nums[j] - nums[i]);
                }
            }
        }
        return maxd;
    }
};