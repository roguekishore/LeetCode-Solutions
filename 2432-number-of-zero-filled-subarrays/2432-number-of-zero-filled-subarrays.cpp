class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long result = 0;
        long long consecutive = 0;

        for(int i=0 ; i<nums.size() ; i++) {
            if(nums[i]==0) {
                consecutive++;
                result += consecutive;
            } else {
                consecutive = 0;
            }
        }

        return result;
    }
};