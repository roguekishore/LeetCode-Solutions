class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int size = nums.size();
        long long count = 0, left = 0;
        int tempCount = 0;
        int max = *max_element(nums.begin(), nums.end());


        for(int right = 0 ; right<size ; right++) {
            if(nums[right] == max) {
                tempCount++;
            }

            while(left<=right && tempCount==k) {
                if(nums[left] == max) {
                    tempCount--;
                }
                left++;
            }

            count+=left;
        }

        return count;
    }
};