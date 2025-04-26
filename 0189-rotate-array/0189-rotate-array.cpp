class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        if(size == 1 || k == size || k%size==0 ) {
            return;
        }

        vector<int> demo;
        int count = k%size;
        int right = size - count;

        while( right < size ) {
            demo.push_back(nums[right++]);
        }

        int left = 0;
        while( left < size-count ) {
            demo.push_back(nums[left++]);
        }

        nums = demo;
        

    }
};