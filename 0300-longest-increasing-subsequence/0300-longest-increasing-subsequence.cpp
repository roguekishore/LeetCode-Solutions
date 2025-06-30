class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(nums.size(), 1);
        for(int i=0 ; i<size ; i++) {
            for(int j=0 ; j<i ; j++) {
                if(nums[i] > nums[j])
                    dp[i] = max(dp[i], 1 + dp[j]);
            }
        }

        int maxi = INT_MIN;
        for(int i=0 ; i<size ; i++) {
            maxi = max(dp[i], maxi); 
        }

        return maxi;
    }
};