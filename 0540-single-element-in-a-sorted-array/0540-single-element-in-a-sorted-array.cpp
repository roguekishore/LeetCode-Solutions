class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while(left < right) {
            int mid = left + (right-left) / 2;
            
            if(mid%2 == 1) {
                mid -= 1;
            }

            if(nums[mid] != nums[mid+1]) {
                right = mid;
            }

            else {
                left = mid + 2;
            }
        }

        return nums[left];
    }
};