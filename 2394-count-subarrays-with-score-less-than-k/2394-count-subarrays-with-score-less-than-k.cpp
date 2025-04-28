class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int size = nums.size();
        long count = 0;

        int left = 0;
        long result = 0;

        // brute force solution
        // for(int left = 0 ; left<size ; left++) {
        //     result = 0;

        //     for(int right = left ; right<size ; right++) {
        //         result += nums[right];
        //         if(result*(right - left + 1) < k) {
        //             count++;
        //         } 
        //         else {
        //             break;
        //         }
        //     }
        // }

        for(int right = 0 ; right<size ; right++) {
            result += nums[right];
            while( result * (right - left + 1) >=k ) {
                result -= nums[left++];
            }
            count += right-left+1; /* if window size is 2 for left = 0 and right = 1
                                      then subarray 0,1 and [0,1] is valid */
        }

        return count;
    }
};